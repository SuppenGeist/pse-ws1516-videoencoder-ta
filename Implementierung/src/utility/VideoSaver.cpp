#include "VideoSaver.h"

#include <QString>
#include <QDebug>

#include <memory>
#include <thread>

#include <cstdio>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include<libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libavutil/timestamp.h>
}

#include "VideoConverter.h"
#include "../model/AVVideo.h"

Utility::VideoSaver::VideoSaver(Model::Video *video, QString filename):video_(video),
	filename_(filename) {
}

Utility::VideoSaver::~VideoSaver() {
	isRunning_=false;
	if(saver_.joinable())
		saver_.join();
}

void Utility::VideoSaver::saveP() {
	isRunning_=true;
	auto converter=std::make_unique<VideoConverter>(video_);
	auto video=std::make_unique<Model::AVVideo>();
	converter->convertVideoToAVVideo(video.get());
	std::string fn=filename_.toUtf8().constData();
	const char* filename=fn.c_str();
	const AVCodecID codecID=AV_CODEC_ID_H264;

	AVCodec* codec;
	AVCodecContext* context=NULL;
	AVOutputFormat* ofmt=NULL;
	AVFormatContext* ofmt_ctx=NULL;

	int ret;
	int got_output;

	AVFrame* frame;
	AVPacket pckt;

	codec=avcodec_find_encoder(codecID);

	avformat_alloc_output_context2(&ofmt_ctx,NULL,NULL,filename);

	ofmt=ofmt_ctx->oformat;




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
	context->pix_fmt=AV_PIX_FMT_YUV444P;

	if(codecID==AV_CODEC_ID_H264) {
		av_opt_set(context->priv_data,"preset","veryslow",0);
		av_opt_set(context->priv_data,"crf","0",0);
	}

	if(avcodec_open2(context,codec,NULL)<0) {
		isRunning_=false;
		return;
	}

	AVStream* ostream = avformat_new_stream(ofmt_ctx,codec);
	ostream->time_base=fps;
	avcodec_copy_context(ostream->codec,context);
	ostream->codec->codec_tag=0;
	//if (ofmt_ctx->oformat->flags & AVFMT_GLOBALHEADER)
	ostream->codec->flags |= (1<<22);

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

	avio_open(&ofmt_ctx->pb,filename,AVIO_FLAG_WRITE);

	avformat_write_header(ofmt_ctx,NULL);

	struct SwsContext* swsContext = sws_getContext(context->width,
	                                context->height,
	                                AV_PIX_FMT_RGB24,
	                                context->width,
	                                context->height,
	                                AV_PIX_FMT_YUV444P,
	                                0,
	                                0,
	                                0,
	                                0
	                                              );

	std::size_t i=0;
	do {
		for(; i<video->getNumberOfFrames()&&isRunning_; i++) {
			av_init_packet(&pckt);
			pckt.data=NULL;
			pckt.size=0;

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
				av_rescale_q_rnd(pckt.pts, fps, ostream->time_base,
				                 (AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
				av_rescale_q_rnd(pckt.dts, fps, ostream->time_base,
				                 (AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
				av_packet_rescale_ts(&pckt,fps,ostream->time_base);
				av_interleaved_write_frame(ofmt_ctx,&pckt);
				av_packet_unref(&pckt);
			}
		}
	} while(isRunning_&&!video->isComplete());

	for(got_output=1; got_output&&isRunning_;) {
		ret=avcodec_encode_video2(context,&pckt,NULL,&got_output);

		if(ret<0) {
			isRunning_=false;
		}

		if(got_output) {
			av_rescale_q_rnd(pckt.pts, fps, ostream->time_base,
			                 (AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
			av_rescale_q_rnd(pckt.dts, fps, ostream->time_base,
			                 (AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
			av_packet_rescale_ts(&pckt,fps,ostream->time_base);
			av_interleaved_write_frame(ofmt_ctx,&pckt);
			av_packet_unref(&pckt);
		}
	}
	av_write_trailer(ofmt_ctx);
	avio_closep(&ofmt_ctx->pb);
	avformat_free_context(ofmt_ctx);

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

void Utility::VideoSaver::join() {
	saver_.join();
}
