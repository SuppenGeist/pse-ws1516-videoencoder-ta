#include "VideoSaver.h"
#include <QString>
#include <memory>
#include "../model/AVVideo.h"
#include "VideoConverter.h"
#include "../model/AVVideo.h"
 extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include<libswscale/swscale.h>
#include <libavutil/imgutils.h>
 }
static uint8_t *video_buffer_;
static int video_buffer_size_;
 Utility::VideoSaver::VideoSaver() {
        }
void Utility::VideoSaver::saveVideo(Model::Video* video, QString filename) {
    QByteArray ba = filename.toLatin1(); //byte array to get QString as const char*
    const char* filename_ = ba.data();
    std::unique_ptr<Model::AVVideo> video_ = VideoConverter::convertVideoToAVVideo(*video);
    AVCodec *codec_;
    FILE *file;
    AVCodecContext *c = NULL;
    int bufferSize_ = 400000,outputSize_,picBufferSize_;
    uint8_t *buffer = new uint8_t[400000];
    AVFrame* picture;

    //find codec
    codec_ = avcodec_find_encoder(CODEC_ID_H264);
    //set codecContext
    c = avcodec_alloc_context3(codec_);

    c->codec_id=CODEC_ID_H264;
    c->pix_fmt = AVPixelFormat::PIX_FMT_YUV420P;

    c->height = video_->getHeight();
    c->width = video_->getWidth();
    c->time_base.den = video_->getFps();
    c->time_base.num = 1;
    c->gop_size = 10;
    c->max_b_frames=1;

    avcodec_open2(c,codec_,NULL);
    file = fopen(filename_, "w+b");


 picBufferSize_ = avpicture_get_size(PIX_FMT_YUV420P, c->width, c->height);
 picture = avcodec_alloc_frame();
    for(unsigned int i = 0; i < video_->getNumberOfFrames();i++){
        fflush(stdout);

        // allocating the buffer
        uint8_t* pictureBuffer_ = (uint8_t*)av_malloc(picBufferSize_*sizeof(uint8_t));

        // setting frame pts (needed for H264 converter)
        picture->pts = (int64_t)((float)i * (1000.0/((float)(c->time_base.den))) * 90);
        // clear picture
        avpicture_fill((AVPicture*)picture, pictureBuffer_, PIX_FMT_YUV420P, c->width, c->height);

        av_image_alloc(picture->data, picture->linesize, c->width, c->height, c->pix_fmt, 1);

        //converting the pixelFormat to yuv420
        struct SwsContext* swsContext = sws_getContext(c->width, c->height,AVPixelFormat::AV_PIX_FMT_RGB24, c->width, c->height, AVPixelFormat::PIX_FMT_YUV420P, SWS_FAST_BILINEAR, NULL, NULL, NULL);
        sws_scale(swsContext, video_->getFrame(i)->data, video_->getFrame(i)->linesize, 0, c->height, picture->data, picture->linesize);
        //setting these for less encoder warnings
        picture->format = AVPixelFormat::PIX_FMT_YUV420P;
        picture->width = c->width;
        picture->height = c->height;
        outputSize_ = avcodec_encode_video(c, buffer, bufferSize_, picture);
        fwrite(buffer, 1, outputSize_, file);

        // freeing memory
        av_free(pictureBuffer_);




    }
    //catch the delayed images
    while(outputSize_) {
        fflush(stdout);
        outputSize_ = avcodec_encode_video(c, buffer, bufferSize_, NULL);
        fwrite(buffer, 1, outputSize_, file);
    }
    fwrite(buffer, 1, 4, file);
    fclose(file);
    delete buffer;
    avcodec_close(c);
    av_free(c);
        av_free(picture);
}
