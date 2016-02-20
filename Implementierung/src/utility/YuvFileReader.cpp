#include "YuvFileReader.h"

#include <memory>
#include <thread>

#include <QFile>
#include <QDebug>
#include <QDataStream>

#include "../model/Video.h"

Utility::YuvFileReader::YuvFileReader(QString filename, int width, int height,
                                      int frameSize): file_(filename),width_(width),height_(height),frameSize_(frameSize),
	isRunning_(false) {
	file_.open(QIODevice::ReadOnly);
	dataStream_.setDevice(&file_);
	binaryData_=new unsigned char[frameSize_];
}

Utility::YuvFileReader::~YuvFileReader() {
	stopReading();

	if(reader_.joinable()) {
		reader_.join();
	}

	delete [] binaryData_;
}

void Utility::YuvFileReader::read(Model::Video *target) {
	if(!target)
		return;
	if(isRunning_)
		return;

	video_=target;

	reader_=std::thread(&YuvFileReader::readP,this);
}

void Utility::YuvFileReader::stopReading() {
	if(isRunning_) {
		isRunning_=false;
	}
}

bool Utility::YuvFileReader::isRunning() {
	return isRunning_;
}

int Utility::YuvFileReader::clamp(int value) {
	if(value<0)
		return 0;
	if(value>255)
		return 255;
	return value;
}

void Utility::YuvFileReader::readP() {
	std::unique_ptr<QImage> frame;
	isRunning_=true;
    while(!dataStream_.atEnd()&&isRunning_) {
		dataStream_.readRawData(reinterpret_cast<char*>(binaryData_),frameSize_);
		video_->appendFrame(std::move(parseNextFrame()));
	}
	isRunning_=false;
    video_->setIsComplete(true);
}
