#include "Yuv411FileReader.h"

#include <memory>
#include <vector>

#include <QString>
#include <QImage>
#include <stdexcept>

#include "Compression.h"
#include "Yuv411Vector.h"
#include "Yuv444Vector.h"
#include "YuvFileReader.h"
#include "Yuv444FileReader.h"
#include "../model/Video.h"

Utility::Yuv411FileReader::Yuv411FileReader(QString filename, int width, int height,
        Compression compression):YuvFileReader(filename,width,height,width*height+width*height/2),compression_(compression) {

}


std::unique_ptr<QImage> Utility::Yuv411FileReader::parseNextFrame() {
    position_=0;
	auto frame=std::make_unique<QImage>(width_,height_,QImage::Format_RGB888);

    Yuv411Vector (Yuv411FileReader::*func_read)()=nullptr;

	if(compression_==Compression::PACKED) {
		func_read=&Yuv411FileReader::readNextVectorPacked;
	} else if(compression_==Compression::PLANAR) {
		func_read=&Yuv411FileReader::readNextVectorPlanar;
	} else {
		throw std::logic_error("Should not get here");
	}

	for (int i = 0; i < height_*width_; i+=4) {
        auto vec=(this->*func_read)();

		auto pixels=Yuv411ToRgb888(vec);
		frame->setPixel(i%width_,i/width_,pixels[0]);
		frame->setPixel((i+1)%width_,(i+1)/width_,pixels[1]);
		frame->setPixel((i+2)%width_,(i+1)/width_,pixels[2]);
		frame->setPixel((i+3)%width_,(i+1)/width_,pixels[3]);
	}

	return std::move(frame);
}

Utility::Yuv411Vector Utility::Yuv411FileReader::readNextVectorPacked() {
    auto u=binaryData_[position_];
    auto y1=binaryData_[position_+1];
    auto y2=binaryData_[position_+2];
    auto v=binaryData_[position_+3];
    auto y3=binaryData_[position_+4];
    auto y4=binaryData_[position_+5];

    position_+=6;
    return Yuv411Vector(u,y1,y2,v,y3,y4);
}

Utility::Yuv411Vector Utility::Yuv411FileReader::readNextVectorPlanar() {
    int numberOfPixels=width_*height_;

    auto y1=binaryData_[position_];
    auto y2=binaryData_[position_+1];
    auto y3=binaryData_[position_+2];
    auto y4=binaryData_[position_+3];
    auto u=binaryData_[numberOfPixels+position_/4];
    auto v=binaryData_[numberOfPixels+numberOfPixels/4+position_/4];

    position_+=4;
    return Yuv411Vector(u,y1,y2,v,y3,y4);
}

std::vector<QRgb> Utility::Yuv411FileReader::Yuv411ToRgb888(Yuv411Vector vector) {
	std::vector<QRgb> returnVec;

	Yuv444Vector vec1(vector.getY1(),vector.getU(),vector.getV());
	Yuv444Vector vec2(vector.getY2(),vector.getU(),vector.getV());
	Yuv444Vector vec3(vector.getY3(),vector.getU(),vector.getV());
	Yuv444Vector vec4(vector.getY4(),vector.getU(),vector.getV());

	returnVec.push_back(Yuv444FileReader::Yuv444ToRgb888(vec1));
	returnVec.push_back(Yuv444FileReader::Yuv444ToRgb888(vec2));
	returnVec.push_back(Yuv444FileReader::Yuv444ToRgb888(vec3));
	returnVec.push_back(Yuv444FileReader::Yuv444ToRgb888(vec4));

	return std::move(returnVec);
}
