#include "Yuv420FileReader.h"

#include <memory>

#include <QString>
#include <QImage>
#include <QDebug>

#include "Yuv444Vector.h"
#include "YuvFileReader.h"
#include "../model/Video.h"
#include "Yuv444FileReader.h"

Utility::Yuv420FileReader::Yuv420FileReader(QString filename, int width,
        int height):YuvFileReader(filename,width,height,width*height+width*height/2) {

}

std::unique_ptr<QImage> Utility::Yuv420FileReader::parseNextFrame() {
	auto frame=std::make_unique<QImage>(width_,height_,QImage::Format_RGB888);
	position_=0;

	for (int i = 0; i < height_; i++) {
		for(int k=0; k<width_; k++) {
			auto vec=readNextVector();

			frame->setPixel(k,i,Yuv444FileReader::Yuv444ToRgb888(vec));
		}
	}
	return std::move(frame);
}

Utility::Yuv444Vector Utility::Yuv420FileReader::readNextVector() {
	int xp=position_%width_;
	int yp=position_/width_;

	auto y=binaryData_[yp*width_+xp];
	int offset1=(yp/2)*(width_/2)+(xp/2)+width_*height_;
	auto u=binaryData_[offset1];
	auto v=binaryData_[offset1+(width_*height_/4)];

	position_++;

	return Yuv444Vector(y,u,v);
}
