#include "VideoConverter.h"

#include <QImage>
#include <QDebug>

#include <memory>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include "../model/Video.h"
#include "../model/AVVideo.h"

Utility::VideoConverter::VideoConverter() {

}

std::unique_ptr<QImage> Utility::VideoConverter::convertAVFrameToQImage(AVFrame& frame) {
	auto image=std::make_unique<QImage>(frame.width,frame.height,QImage::Format_RGB888);

	const int width=frame.width;
	const int height=frame.height;

	for(int y=0; y<height; y++) {
		memcpy(image->scanLine(y),frame.data[0]+y*frame.linesize[0],width*3);
	}

	return std::move(image);
}

std::unique_ptr<Model::Video> Utility::VideoConverter::convertAVVideoToVideo(
    Model::AVVideo& avvideo) {
    auto video = std::make_unique<Model::Video>(avvideo.getFps());

	for(std::size_t i = 0; i < avvideo.getNumberOfFrames(); i++) {
		video->appendFrame(convertAVFrameToQImage(*avvideo.getFrame(i)));
	}

	return std::move(video);
}

AVFrame* Utility::VideoConverter::convertQImageToAVFrame(QImage& image) {
	//CAUTION: This code is VERY slow. Improve if possible.
	const int width=image.width();
	const int height=image.height();

	auto frame=av_frame_alloc();
	frame->width=width;
	frame->height=height;
	frame->format=AV_PIX_FMT_RGB24;

	int size=avpicture_get_size(AV_PIX_FMT_RGB24,width,height);
	uint8_t* data=(uint8_t*)av_malloc(size);
	for(int i=0; i<height; i++) {
		for(int k=0; k<width; k++) {
			auto pixel=image.pixel(k,i);
			data[i*3*width+3*k]=qRed(pixel);
			data[i*3*width+3*k+1]=qGreen(pixel);
			data[i*3*width+3*k+2]=qBlue(pixel);
		}
	}
	avpicture_fill((AVPicture*)frame,data,AV_PIX_FMT_RGB24,width,height);

	return frame;
}
std::unique_ptr<Model::AVVideo> Utility::VideoConverter::convertVideoToAVVideo(
    Model::Video& video) {
    auto avvideo = std::make_unique<Model::AVVideo>(video.getFps());

	for(std::size_t i = 0; i < video.getNumberOfFrames(); i++) {
		avvideo->appendFrame(convertQImageToAVFrame(*video.getFrame(i)));
	}

	return std::move(avvideo);
}
