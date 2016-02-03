#include "VideoLoader.h"

using namespace Utility;

VideoLoader::VideoLoader(QString path) {
	this->path = path;
}

unique_ptr<Model::AVVideo> VideoLoader::loadVideo() {

	// Contains information about the stream
	AVFormatContext *formatContext = NULL;

	// Contains information about the codex
	AVCodecContext *codecContext = NULL;

	// The coder with wich to decode the video
	AVCodec *codec = NULL;

	// Open video file
	// avformat_open_input(context, path, format, options)
	// format = NULL means autodetect
	if(path != NULL && !path.isEmpty()
	        && avformat_open_input(&formatContext, path.toUtf8(), NULL, NULL)!=0)
		return NULL; // Couldn't open file

	// Retrieve stream information
	if(avformat_find_stream_info(formatContext, NULL)<0)
		return NULL; // Couldn't find stream information

	// Print stream information
	av_dump_format(formatContext, 0, path.toUtf8(), 0);

	// Find the best video stream in context
	int videoStreamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
	if(videoStreamIndex == -1) {
		return NULL; // Did not find a video stream in the file
	}

	// Get a pointer to the codec context for the video stream
	codecContext = formatContext->streams[videoStreamIndex]->codec;

	// Find the decoder for the video stream
	codec = avcodec_find_decoder(codecContext->codec_id);
	if(codec == NULL) {
		return NULL; // Codec not found
	}

	// Open codec
	if(avcodec_open2(codecContext, codec, NULL) < 0)
		return NULL; // Could not open codec

	AVPacket *packet = NULL;
	AVFrame *frame = NULL;
	unique_ptr<Model::AVVideo> video = make_unique<Model::AVVideo>(codecContext->framerate.num,
	                                   codecContext->width, codecContext->height);

	while(av_read_frame(formatContext, packet) >= 0) {
		frame = av_frame_alloc();
		avcodec_decode_video2(codecContext, frame, 0, packet);
        video->insertFrame(make_unique<AVFrame>(*frame), video->getNumberOfFrames());
	}

	return video;
}
