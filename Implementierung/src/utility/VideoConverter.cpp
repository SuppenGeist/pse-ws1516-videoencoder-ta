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

std::unique_ptr<QImage> Utility::VideoConverter::convertAVFrameToQImage(AVFrame& frame) {
	auto image=std::make_unique<QImage>(frame.width,frame.height,QImage::Format_RGB888);

	const int width=frame.width;
	const int height=frame.height;

	for(int y=0; y<height; y++) {
		memcpy(image->scanLine(y),frame.data[0]+y*frame.linesize[0],width*3);
	}

	return std::move(image);
}

void Utility::VideoConverter::convertAVVideoToVideo(Model::Video *target) {
    if(!target||!avvideo_)
        return;

    videoTarget_=target;

    converter_=std::thread(&VideoConverter::convertAVVideoP,this);
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

std::unique_ptr<QImage> Utility::VideoConverter::convertGraphToImage(Model::Graph *graph, int width, int height, GUI::GraphCalculator *calculator)
{
    if(!graph) {
        return std::make_unique<QImage>(width,height,QImage::Format_ARGB32_Premultiplied);
    }
    std::unique_ptr<GUI::GraphCalculator> defaultCalculator;
    GUI::GraphCalculator* usedCalculator=nullptr;
    if(calculator) {
        usedCalculator=calculator;
    }else {
        defaultCalculator=std::make_unique<GUI::GraphCalculator>();
        usedCalculator=defaultCalculator.get();
    }
    usedCalculator->setGraph(graph);

    return usedCalculator->toImage(width,height);
}

std::unique_ptr<Model::Video> Utility::VideoConverter::convertGraphVideoToVideo(Model::GraphVideo *video, int width, int height, GUI::GraphCalculator *calculator)
{
    if(!video) {
        return std::make_unique<Model::Video>();
    }
    std::unique_ptr<GUI::GraphCalculator> defaultCalculator;
    GUI::GraphCalculator* usedCalculator=nullptr;
    if(calculator) {
        usedCalculator=calculator;
    }else {
        defaultCalculator=std::make_unique<GUI::GraphCalculator>();
        usedCalculator=defaultCalculator.get();
    }

    auto newVideo=std::make_unique<Model::Video>(video->getFps());
    std::size_t i=0;
    do{
    for(;i<video->getNumberOfGraphs();i++) {
        newVideo->appendFrame(convertGraphToImage(video->getGraph(i),width,height,usedCalculator));
    }
    }while(!video->isComplete());
    newVideo->setIsComplete(true);

    return std::move(newVideo);
}

Utility::VideoConverter::VideoConverter(Model::Video *video):video_(video),videoTarget_(nullptr),avvideo_(nullptr),avvideoTarget_(nullptr),isRunning_(false)
{

}

Utility::VideoConverter::VideoConverter(Model::AVVideo *video):video_(nullptr),videoTarget_(nullptr),avvideo_(video),avvideoTarget_(nullptr),isRunning_(false)
{

}

Utility::VideoConverter::~VideoConverter()
{
    isRunning_=false;
    if(converter_.joinable())
        converter_.join();
}

void Utility::VideoConverter::convertVideoToAVVideo(Model::AVVideo *target) {
    if(!target||!video_)
        return;

    avvideoTarget_=target;

    converter_=std::thread(&VideoConverter::convertVideoP,this);
}

void Utility::VideoConverter::convertVideoP()
{
    isRunning_=true;
    avvideoTarget_->setIsComplete(false);
    std::size_t i = 0;
    do {
    for(; i < video_->getNumberOfFrames()&&isRunning_; i++) {
        avvideoTarget_->appendFrame(convertQImageToAVFrame(*video_->getFrame(i)));
    }
    }while(isRunning_&&!video_->isComplete());
    avvideoTarget_->setIsComplete(true);
    avvideoTarget_->setFps(video_->getFps());
    isRunning_=false;
}

void Utility::VideoConverter::convertAVVideoP()
{
    isRunning_=true;
    videoTarget_->setIsComplete(false);
    std::size_t i = 0;
    do {
    for(; i < avvideo_->getNumberOfFrames()&&isRunning_; i++) {
        videoTarget_->appendFrame(convertAVFrameToQImage(*avvideo_->getFrame(i)));
    }
    }
    while(isRunning_&&!avvideo_->isComplete());
    videoTarget_->setIsComplete(true);
    videoTarget_->setFps(avvideo_->getFps());
    isRunning_=false;
}
