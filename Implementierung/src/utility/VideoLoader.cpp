#include "VideoLoader.h"

#include <thread>

#include <QDebug>


Utility::VideoLoader::VideoLoader(QString path, AVDictionary *dict):path_(path),isRunning_(false),
	dict_(dict),codec_(""),averageBitrate_(0) {

}

Utility::VideoLoader::~VideoLoader() {
	isRunning_=false;

	if(loader_.joinable()) {
		loader_.join();
	}
}

void Utility::VideoLoader::loadVideo(Model::AVVideo* target) {
	if(!target)
		return;
	target_=target;

	loader_=std::thread(&VideoLoader::loadP,this);
}

QString Utility::VideoLoader::getCodec() {
	return codec_;
}

int Utility::VideoLoader::getAverageBitrate() {
	return averageBitrate_;
}

void Utility::VideoLoader::loadP() {
	isRunning_=true;
	target_->setIsComplete(false);
	// Contains information about the stream
	AVFormatContext *formatContext = NULL;

	// Contains information about the codex
	AVCodecContext *codecContext = NULL;

	// The coder with wich to decode the video
	AVCodec *codec = NULL;

	// Open video file
	// avformat_open_input(context, path, format, options)
	// format = NULL means autodetect
	if(!path_.isEmpty()
	        && avformat_open_input(&formatContext, path_.toUtf8(), NULL, NULL)!=0) {
		return;
	}

	// Retrieve stream information
	if(avformat_find_stream_info(formatContext, NULL)<0) {
		return;
	}

	// Print stream information
	av_dump_format(formatContext, 0, path_.toUtf8(), 0);


	// Find the best video stream in context
	int videoStreamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
	if(videoStreamIndex == -1) {
		return;
	}

	// Get a pointer to the codec context for the video stream
	codecContext = formatContext->streams[videoStreamIndex]->codec;

	// Find the decoder for the video stream
	codec = avcodec_find_decoder(codecContext->codec_id);
	if(codec == NULL) {
		return;
	}

	// Open codec
	if(avcodec_open2(codecContext, codec, &dict_) < 0) {
		return;
	}

	struct SwsContext      *sws_ctx = NULL;

	averageBitrate_=codecContext->bit_rate;
	codec_=QString(av_codec_get_codec_descriptor(codecContext)->name);
	if(codec_=="")
		codec_="N/A";

	sws_ctx =
	    sws_getContext
	    (
	        codecContext->width,
	        codecContext->height,
	        codecContext->pix_fmt,
	        codecContext->width,
	        codecContext->height,
	        AV_PIX_FMT_RGB24,
	        0,
	        0,
	        0,
	        0
	    );

	AVPacket packet;
	AVFrame *frame = NULL;
	frame = av_frame_alloc();

	AVFrame* rgbframe=NULL;
	uint8_t* buffer = NULL;
	int numbytes=avpicture_get_size(AV_PIX_FMT_RGB24, codecContext->width,codecContext->height);

	target_->setFps(codecContext->framerate.num);
	av_init_packet(&packet);
	packet.data = NULL;
	packet.size = 0;
	int gotPicture = 0;
	while(av_read_frame(formatContext, &packet) >= 0&&isRunning_) {
		avcodec_decode_video2(codecContext, frame, &gotPicture, &packet);

		if(gotPicture != 0) {
			rgbframe=av_frame_alloc();

			buffer=(uint8_t *)av_malloc(numbytes*sizeof(uint8_t));
			avpicture_fill((AVPicture *)rgbframe, buffer, AV_PIX_FMT_RGB24,codecContext->width,
			               codecContext->height);
			rgbframe->width=codecContext->width;
			rgbframe->height=codecContext->height;
			rgbframe->format=AV_PIX_FMT_RGB24;
			rgbframe->pkt_size=frame->pkt_size;

			sws_scale
			(
			    sws_ctx,
			    frame->data,
			    frame->linesize,
			    0,
			    codecContext->height,
			    rgbframe->data,
			    rgbframe->linesize
			);

			target_->appendFrame(rgbframe);
		}
	}

	packet.data=NULL;
	packet.size=0;

	while(isRunning_) {
		avcodec_decode_video2(codecContext, frame, &gotPicture, &packet);

		if(gotPicture == 0)
			break;

		rgbframe=av_frame_alloc();

		buffer=(uint8_t *)av_malloc(numbytes*sizeof(uint8_t));
		avpicture_fill((AVPicture *)rgbframe, buffer, AV_PIX_FMT_RGB24,codecContext->width,
		               codecContext->height);
		rgbframe->width=codecContext->width;
		rgbframe->height=codecContext->height;
		rgbframe->format=AV_PIX_FMT_RGB24;
		rgbframe->pkt_size=frame->pkt_size;

		sws_scale
		(
		    sws_ctx,
		    frame->data,
		    frame->linesize,
		    0,
		    codecContext->height,
		    rgbframe->data,
		    rgbframe->linesize
		);

		target_->appendFrame(rgbframe);
	}
	av_frame_unref(frame);
	av_frame_free(&frame);
	avcodec_close(codecContext);
	avformat_close_input(&formatContext);
	isRunning_=false;
	if(dict_) {
		free(dict_);
	}
    target_->setIsComplete(true);
}
