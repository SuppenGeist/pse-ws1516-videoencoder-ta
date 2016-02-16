#include "YuvVideo.h"

#include <memory>
#include <stdexcept>
#include <thread>

#include <QString>

#include "../utility/YuvType.h"
#include "../utility/Compression.h"
#include "Video.h"
#include "AVVideo.h"
#include "../utility/YuvFileReader.h"
#include "../utility/Yuv411FileReader.h"
#include "../utility/Yuv420FileReader.h"
#include "../utility/Yuv422FileReader.h"
#include "../utility/Yuv444FileReader.h"

Model::YuvVideo::YuvVideo(QString path, Utility::YuvType type, Utility::Compression compression,
                          int width, int height, int fps):path_(path),height_(height),width_(width),fps_(fps),
	compression_(compression),yuvType_(type),isComplete_(false) {

}

Model::YuvVideo::~YuvVideo() {
	if(fileReader_.get()) {
		fileReader_->stopReading();
	}
}

QString Model::YuvVideo::getPath() {
	return path_;
}

Utility::Compression Model::YuvVideo::getCompression() {
	return compression_;
}

Utility::YuvType Model::YuvVideo::getYuvType() {
	return yuvType_;
}

int Model::YuvVideo::getWidth() {
	return width_;
}

int Model::YuvVideo::getHeight() {
	return height_;
}

int Model::YuvVideo::getFps() {
    return fps_;
}

Model::GraphVideo &Model::YuvVideo::getRedHistogramm()
{
    if(!redHisto_.get()) {
        calculateHistogramms();
    }

    return *redHisto_;
}

Model::GraphVideo &Model::YuvVideo::getGreenHistogramm()
{
    if(!greenHisto_.get()) {
        calculateHistogramms();
    }

    return *greenHisto_;
}

Model::GraphVideo &Model::YuvVideo::getBlueHistogramm()
{
    if(!blueHisto_.get()) {
        calculateHistogramms();
    }

    return *blueHisto_;
}

Model::AVVideo& Model::YuvVideo::getAvVideo() {
	throw "Not yet implemented";
}

Model::Video& Model::YuvVideo::getVideo() {
	if(!displayVideo_.get())
		loadVideo();
	return *displayVideo_.get();
}


void Model::YuvVideo::loadVideo() {
	if(fileReader_.get()) {
		fileReader_->stopReading();
	}
	switch(yuvType_) {
	case Utility::YuvType::YUV411:
		fileReader_=std::make_unique<Utility::Yuv411FileReader>(path_,width_,height_,compression_);
		break;
	case Utility::YuvType::YUV420:
		fileReader_=std::make_unique<Utility::Yuv420FileReader>(path_,width_,height_);
		break;
	case Utility::YuvType::YUV422:
		fileReader_=std::make_unique<Utility::Yuv422FileReader>(path_,width_,height_,compression_);
		break;
	case Utility::YuvType::YUV444:
		fileReader_=std::make_unique<Utility::Yuv444FileReader>(path_,width_,height_,compression_);
		break;
	default:
		throw std::logic_error("Should not get here");
	}
	displayVideo_=std::make_unique<Video>(fps_);
    fileReader_->read(displayVideo_.get());
}

void Model::YuvVideo::calculateHistogramms()
{
    redHisto_=std::make_unique<GraphVideo>();
    greenHisto_=std::make_unique<GraphVideo>();
    blueHisto_=std::make_unique<GraphVideo>();

    histogrammCalculator_=std::make_unique<Utility::RGBHistogrammCalculator>(getVideo());
    histogrammCalculator_->calculate(redHisto_.get(),greenHisto_.get(),blueHisto_.get());
}


