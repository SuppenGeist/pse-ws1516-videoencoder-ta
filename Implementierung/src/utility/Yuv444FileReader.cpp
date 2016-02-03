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

Utility::Yuv444FileReader::Yuv444FileReader(QString filename, int width, int height, int fps, Compression compression): YuvFileReader(filename, width, height,fps),position_(0),compression_(compression) {

}

std::unique_ptr<Model::Video> Utility::Yuv444FileReader::read() {
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


std::unique_ptr<QImage> Utility::Yuv444FileReader::parseNextFrame() {
    auto frame=std::make_unique<QImage>(width_,height_,QImage::Format_RGB888);

    Yuv444Vector (Yuv444FileReader::*func_read)(bool&)=nullptr;

    if(compression_==Compression::PACKED) {
        func_read=&Yuv444FileReader::readNextVectorPacked;
    }
    else if(compression_==Compression::PLANAR) {
        func_read=&Yuv444FileReader::readNextVectorPlanar;
    }
    else {
        throw std::logic_error("Should not get here");
    }

    bool success=true;
    for (int i = 0; i < height_; i++){
        for(int k=0;k<width_;k++) {
            auto vec=(this->*func_read)(success);

            if(!success) {
                frame.release();
                return std::move(frame);
            }

            frame->setPixel(k,i,Yuv444ToRgb888(vec));
        }
    }

    return std::move(frame);
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPacked(bool &success) {
    if(position_+3>binaryData_.size()) {
        success=false;
        return Yuv444Vector(0,0,0);
    }

    auto y=binaryData_[position_];
    auto u=binaryData_[position_+1];
    auto v=binaryData_[position_+2];

    position_+=3;
    success=true;
    return Yuv444Vector(y,u,v);
}

QRgb Utility::Yuv444FileReader::Yuv444ToRgb888(Yuv444Vector& vector) {
    int y=vector.getY();
    int u=vector.getU();
    int v=vector.getV();

    int r=y + ( ( 1436 * ( v - 128) ) >> 10 );
    int g=y - ( ( 352 * ( u - 128 ) + 731 * ( v - 128 ) ) >> 10 );
    int b=y + ( ( 1812 * ( u - 128 ) ) >> 10 );

    return qRgb(clamp(r),clamp(g),clamp(b));
}

Utility::Yuv444Vector Utility::Yuv444FileReader::readNextVectorPlanar(bool &success) {
    int frameIndex=video_->getNumberOfFrames();
    int numberOfPixels=width_*height_;
    int offset=3*frameIndex*numberOfPixels;

    if(offset+2*numberOfPixels+position_>binaryData_.size()) {
        success=false;
        return Yuv444Vector(0,0,0);
    }

    auto y=binaryData_[offset+position_];
    auto u=binaryData_[offset+numberOfPixels+position_];
    auto v=binaryData_[offset+2*numberOfPixels+position_];

    position_++;
    success=true;
    return Yuv444Vector(y,u,v);
}


