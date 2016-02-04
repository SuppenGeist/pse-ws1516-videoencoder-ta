#include "Yuv422FileReader.h"

#include <memory>
#include <vector>

#include <QImage>
#include <QColor>

#include "../model/Video.h"
#include "Compression.h"
#include "Yuv422Vector.h"
#include "YuvFileReader.h"
#include "Yuv444FileReader.h"
#include "Yuv444Vector.h"

Utility::Yuv422FileReader::Yuv422FileReader(QString filename, int width, int height,int fps,
        Compression compression):YuvFileReader(filename,width,height,fps),compression_(compression) {
}

std::unique_ptr<Model::Video> Utility::Yuv422FileReader::read() {
	video_=std::make_unique<Model::Video>(fps_,width_,height_);

	position_=0;

	std::unique_ptr<QImage> frame;
	while((frame=parseNextFrame()).get()) {
		video_->appendFrame(std::move(frame));

		if(compression_==Compression::PLANAR) {
			position_=0;
		}
	}

	return std::move(video_);
}


std::unique_ptr<QImage> Utility::Yuv422FileReader::parseNextFrame() {
	auto frame=std::make_unique<QImage>(width_,height_,QImage::Format_RGB888);

	Yuv422Vector (Yuv422FileReader::*func_read)(bool&)=nullptr;

	if(compression_==Compression::PACKED) {
		func_read=&Yuv422FileReader::readNextVectorPacked;
	} else if(compression_==Compression::PLANAR) {
		func_read=&Yuv422FileReader::readNextVectorPlanar;
	} else {
		throw std::logic_error("Should not get here");
	}

	bool success=true;
	for (int i = 0; i < height_*width_; i+=2) {
		auto vec=(this->*func_read)(success);

		if(!success) {
			frame.release();
			return std::move(frame);
		}

		auto pixels=Yuv422ToRgb888(vec);
		frame->setPixel(i%width_,i/width_,pixels[0]);
		frame->setPixel((i+1)%width_,(i+1)/width_,pixels[1]);
	}

	return std::move(frame);
}

Utility::Yuv422Vector Utility::Yuv422FileReader::readNextVectorPacked(bool &success) {
	if(position_+4>binaryData_.size()) {
		success=false;
		return Yuv422Vector(0,0,0,0);
	}

	auto u=binaryData_[position_];
	auto y1=binaryData_[position_+1];
	auto v=binaryData_[position_+2];
	auto y2=binaryData_[position_+3];

	position_+=4;
	success=true;
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

Utility::Yuv422Vector Utility::Yuv422FileReader::readNextVectorPlanar(bool &success) {
	int frameIndex=video_->getNumberOfFrames();
	int numberOfPixels=width_*height_;
	int offset=frameIndex*(2*numberOfPixels);

	if(offset+numberOfPixels+position_>binaryData_.size()) {
		success=false;
		return Yuv422Vector(0,0,0,0);
	}

	auto y1=binaryData_[offset+position_];
	auto y2=binaryData_[offset+position_+1];
	auto u=binaryData_[offset+numberOfPixels+position_/2];
	auto v=binaryData_[offset+numberOfPixels+numberOfPixels/2+position_/2];

	position_+=2;
	success=true;
	return Yuv422Vector(u,y1,v,y2);
}
