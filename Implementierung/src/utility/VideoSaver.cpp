#include "VideoSaver.h"

#include <QString>
#include <QDebug>

#include <memory>
#include <thread>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include<libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
}

#include "VideoConverter.h"
#include "../model/AVVideo.h"

Utility::VideoSaver::VideoSaver(Model::Video *video, QString filename):video_(video),filename_(filename) {
}

Utility::VideoSaver::~VideoSaver()
{
    isRunning_=false;
    if(saver_.joinable())
        saver_.join();
}

void Utility::VideoSaver::saveP()
{
    isRunning_=true;
    auto converter=std::make_unique<VideoConverter>(video_);
    auto video=std::make_unique<Model::AVVideo>();
    converter->convertVideoToAVVideo(video.get());
    std::string fn=filename_.toUtf8().constData();
    const char* filename=fn.c_str();
    const AVCodecID codecID=AV_CODEC_ID_H264;

    AVCodec* codec;
    AVCodecContext* context=NULL;

    int ret;
    int got_output;

    FILE* f;

    AVFrame* frame;
    AVPacket pckt;
    uint8_t endcode[]={0,0,1,0xb7};

    codec=avcodec_find_encoder(codecID);

    if(!codec) {
        isRunning_=false;
        return;
    }

    context=avcodec_alloc_context3(codec);
    if(!context) {
        isRunning_=false;
        return;
    }

    AVRational fps;
    fps.num=1;
    fps.den=video_->getFps();

    context->width=video_->getWidth();
    context->height=video_->getHeight();
    context->time_base=fps;
    context->gop_size=10;
    context->max_b_frames=1;
    context->pix_fmt=AV_PIX_FMT_YUV420P;

    if(codecID==AV_CODEC_ID_H264) {
        av_opt_set(context->priv_data,"preset","slow",0);
    }

    if(avcodec_open2(context,codec,NULL)<0) {
        isRunning_=false;
        return;
    }

    f=fopen(filename,"wb");
    if(!f) {
        qDebug()<<"Could not open file";
        isRunning_=false;
        return;
    }

    frame=av_frame_alloc();
    if(!frame) {
        isRunning_=false;
        return;
    }

    frame->format=context->pix_fmt;
    frame->width=context->width;
    frame->height=context->height;

    ret=av_image_alloc(frame->data,frame->linesize,context->width,context->height,context->pix_fmt,32);
    if(ret<0) {
        isRunning_=false;
        return;
    }

    struct SwsContext* swsContext = sws_getContext(context->width,
                                                   context->height,
                                                   AV_PIX_FMT_RGB24,
                                                   context->width,
                                                   context->height,
                                                   AV_PIX_FMT_YUV420P,
                                                   0,
                                                   0,
                                                   0,
                                                   0
                                         );

    std::size_t i=0;
    do {
    for(;i<video->getNumberOfFrames()&&isRunning_;i++) {
        av_init_packet(&pckt);
        pckt.data=NULL;
        pckt.size=0;

        fflush(stdout);

        sws_scale(
                    swsContext,
                    video->getFrame(i)->data,
                    video->getFrame(i)->linesize,
                    0,
                    context->height,
                    frame->data,
                    frame->linesize
        );

        frame->pts=i;

        ret=avcodec_encode_video2(context,&pckt,frame,&got_output);
        if(ret<0) {
            isRunning_=false;
            return;
        }

        if(got_output) {
            fwrite(pckt.data,1,pckt.size,f);
            av_packet_unref(&pckt);
        }
    }
    }while(isRunning_&&!video->isComplete());

    for(got_output=1;got_output;) {
        fflush(stdout);

        ret=avcodec_encode_video2(context,&pckt,NULL,&got_output);
        if(ret<0) {
            fclose(f);
            isRunning_=false;
            return;
        }

        if(got_output) {
            fwrite(pckt.data,1,pckt.size,f);
            av_packet_unref(&pckt);
        }
    }

    fwrite(endcode,1,sizeof(endcode),f);
    fclose(f);

    avcodec_close(context);
    av_free(context);
    av_freep(&frame->data[0]);
    av_frame_free(&frame);

    isRunning_=false;
}

void Utility::VideoSaver::save() {
    if(!video_)
        return;

    saver_=std::thread(&VideoSaver::saveP,this);
}

void Utility::VideoSaver::join()
{
    saver_.join();
}
