#include "Yuv420FileReader.h"

#include <memory>

#include <QString>
#include <QImage>
#include <QDebug>

#include "Yuv444Vector.h"
#include "YuvFileReader.h"
#include "../model/Video.h"
#include "Yuv444FileReader.h"

Utility::Yuv420FileReader::Yuv420FileReader(QString filename, int width, int height, int fps):YuvFileReader(filename,width,height,fps) {

}

std::unique_ptr<Model::Video> Utility::Yuv420FileReader::read() {
    video_=std::make_unique<Model::Video>(fps_,width_,height_);

    position_=0;

    std::unique_ptr<QImage> frame;
    while((frame=parseNextFrame()).get()) {
        video_->appendFrame(std::move(frame));
    }
    qDebug()<<video_->getNumberOfFrames();
    return std::move(video_);
}

std::unique_ptr<QImage> Utility::Yuv420FileReader::parseNextFrame() {
    auto frame=std::make_unique<QImage>(width_,height_,QImage::Format_RGB888);
    position_=0;

    bool success=true;
    for (int i = 0; i < height_; i++){
        for(int k=0;k<width_;k++) {
            auto vec=readNextVector(success);

            if(!success) {
                frame.release();
                return std::move(frame);
            }

            frame->setPixel(k,i,Yuv444FileReader::Yuv444ToRgb888(vec));
        }
    }
    return std::move(frame);
}

Utility::Yuv444Vector Utility::Yuv420FileReader::readNextVector(bool& success) {
    int frameNumber=video_->getNumberOfFrames();

    if((frameNumber+1)*width_*height_*1.5>=binaryData_.size()) {
           success=false;
           return Yuv444Vector(0,0,0);
    }

    int offset=frameNumber*width_*height_*1.5;
    int xp=position_%width_;
    int yp=position_/width_;

    auto y=binaryData_[offset+yp*width_+xp];
    auto u=binaryData_[offset+(yp/2)*(width_/2)+(xp/2)+width_*height_];
    auto v=binaryData_[offset+(yp/2)*(width_/2)+(xp/2)+width_*height_+(width_*height_/4)];

    position_++;

    return Yuv444Vector(y,u,v);
}
