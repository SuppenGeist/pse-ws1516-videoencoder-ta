#include "Yuv422FileReader.h"

#include <memory>
#include <vector>

#include <QImage>
#include <QDebug>
#include <QColor>

#include "../model/Video.h"
#include "Compression.h"
#include "Yuv422Vector.h"
#include "YuvFileReader.h"
#include "Yuv444FileReader.h"
#include "Yuv444Vector.h"

Utility::Yuv422FileReader::Yuv422FileReader(QString filename, int width, int height,
        Compression compression):YuvFileReader(filename,width,height,2*width*height),
	compression_(compression) {
}


std::unique_ptr<QImage> Utility::Yuv422FileReader::parseNextFrame() {
	position_=0;
	auto frame=std::make_unique<QImage>(width_,height_,QImage::Format_RGB888);

	Yuv422Vector (Yuv422FileReader::*func_read)()=nullptr;

	if(compression_==Compression::PACKED) {
		func_read=&Yuv422FileReader::readNextVectorPacked;
	} else if(compression_==Compression::PLANAR) {
		func_read=&Yuv422FileReader::readNextVectorPlanar;
	} else {
		throw std::logic_error("Should not get here");
	}

	for (int i = 0; i < height_*width_; i+=2) {
		auto vec=(this->*func_read)();

		auto pixels=Yuv422ToRgb888(vec);
		frame->setPixel(i%width_,i/width_,pixels[0]);
		frame->setPixel((i+1)%width_,(i+1)/width_,pixels[1]);
	}

	return std::move(frame);
}

Utility::Yuv422Vector Utility::Yuv422FileReader::readNextVectorPacked() {
	auto u=binaryData_[position_];
	auto y1=binaryData_[position_+1];
	auto v=binaryData_[position_+2];
	auto y2=binaryData_[position_+3];

	position_+=4;
	return Yuv422Vector(u,y1,v,y2);
}

std::vector<QRgb> Utility::Yuv422FileReader::Yuv422ToRgb888(Yuv422Vector vector) {
	std::vector<QRgb> returnVec;

	Yuv444Vector vec1(vector.getY1(),vector.getU(),vector.getV());
	Yuv444Vector vec2(vector.getY2(),vector.getU(),vector.getV());
	returnVec.push_back(Yuv444FileReader::Yuv444ToRgb888(vec1));
	returnVec.push_back(Yuv444FileReader::Yuv444ToRgb888(vec2));

	return std::move(returnVec);
}

Utility::Yuv422Vector Utility::Yuv422FileReader::readNextVectorPlanar() {
	int numberOfPixels=width_*height_;

	auto y1=binaryData_[position_];
	auto y2=binaryData_[position_+1];
	auto u=binaryData_[numberOfPixels+position_/2];
	auto v=binaryData_[numberOfPixels+numberOfPixels/2+position_/2];

	position_+=2;
	return Yuv422Vector(u,y1,v,y2);
}
