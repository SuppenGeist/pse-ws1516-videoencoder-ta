#include "YuvFileReader.h"

#include <memory>

#include <QFile>
#include <QDataStream>

#include "../model/Video.h"

Utility::YuvFileReader::YuvFileReader(QString filename, int width, int height, int frameSize): file_(filename),width_(width),height_(height),frameSize_(frameSize) {
	file_.open(QIODevice::ReadOnly);
    dataStream_.setDevice(&file_);
}

void Utility::YuvFileReader::read(Model::Video *target)
{
    if(!target)
        return;
    video_=target;

    std::unique_ptr<QImage> frame;
    while(!dataStream_.atEnd()) {
        binaryData_=new unsigned char[frameSize_];
        dataStream_.readRawData(reinterpret_cast<char*>(binaryData_),frameSize_);
        target->appendFrame(std::move(parseNextFrame()));
        delete [] binaryData_;
    }
}

int Utility::YuvFileReader::clamp(int value) {
	if(value<0)
		return 0;
	if(value>255)
		return 255;
	return value;
}
