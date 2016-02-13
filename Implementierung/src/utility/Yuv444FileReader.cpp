#include "Yuv444FileReader.h"

#include <memory>
#include <stdexcept>

#include <QString>
#include <QImage>
#include <QColor>
#include <QDebug>

#include "Compression.h"
#include "YuvFileReader.h"
#include "../model/Video.h"
#include "Yuv444Vector.h"

Utility::Yuv444FileReader::Yuv444FileReader(QString filename, int width, int height,
        Compression compression): YuvFileReader(filename, width, height,width*height*3),position_(0),
	compression_(compression) {

}

std::unique_ptr<QImage> Utility::Yuv444FileReader::parseNextFrame() {
	position_=0;
	auto frame=std::make_unique<QImage>(width_,height_,QImage::Format_RGB888);

	Yuv444Vector (Yuv444FileReader::*func_read)(void)=nullptr;

	if(compression_==Compression::PACKED) {
		func_read=&Yuv444FileReader::readNextVectorPacked;
	} else if(compression_==Compression::PLANAR) {
		func_read=&Yuv444FileReader::readNextVectorPlanar;
	} else {
		throw std::logic_error("Should not get here");
	}

	for (int i = 0; i < height_; i++) {
		for(int k=0; k<width_; k++) {
			auto vec=(this->*func_read)();

			frame->setPixel(k,i,Yuv444ToRgb888(vec));
		}
	}

	return std::move(frame);
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPacked() {
	auto y=binaryData_[position_];
	auto u=binaryData_[position_+1];
	auto v=binaryData_[position_+2];

	position_+=3;
	return Yuv444Vector(y,u,v);
}

QRgb Utility::Yuv444FileReader::Yuv444ToRgb888(Yuv444Vector& vector) {
	int y=vector.getY();
	int u=vector.getU();
	int v=vector.getV();

    int r=1.164*(y-16)+1.596*(v-128);
    int g=1.164*(y-16)-0.813*(v-128)-0.391*(u-128);
    int b=1.164*(y-16)+2.018*(u-128);

    /*
    int r=y + ( ( 1436 * ( v - 128) ) >> 10 );
    int g=y - ( ( 352 * ( u - 128 ) + 731 * ( v - 128 ) ) >> 10 );
    int b=y + ( ( 1812 * ( u - 128 ) ) >> 10 );
    */
	return qRgb(clamp(r),clamp(g),clamp(b));
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPlanar() {
	int numberOfPixels=width_*height_;

	auto y=binaryData_[position_];
	auto u=binaryData_[numberOfPixels+position_];
	auto v=binaryData_[2*numberOfPixels+position_];

	position_++;
	return Yuv444Vector(y,u,v);
}


