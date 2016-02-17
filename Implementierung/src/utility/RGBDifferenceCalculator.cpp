#include "RGBDifferenceCalculator.h"

#include "../model/Video.h"

#include <QColor>

Utility::RGBDifferenceCalculator::RGBDifferenceCalculator(Model::Video& referenceVideo,
        Model::Video& video) {
	this->referenceVideo = &referenceVideo;
	this->video = &video;
}

void Utility::RGBDifferenceCalculator::calculateVideo(Model::Video& target) {
    isRunning = true;
    std::size_t i=0;
    do {
        for(; i < video_->getNumberOfFrames()&&isRunning_; i++) {
            QImage *currentFrame = video_->getFrame(i);
            QImage *refCurrentFrame = referenceVideo_->getFrame(i);
            auto *outFrame = new QImage(currentFrame->getHeight(), currentFrame->getWidth(), currentFrame->format);
            for(int j = 0; j < currentFrame->height(); j++) {
                for(int k = 0; k < currentFrame->width(); k++) {
                    auto pixel=currentFrame->pixel(k,j);
                    auto refPixel=refCurrentFrame->pixel(k,j);
                    int blue =  std::abs (qBlue(pixel)-qBlue(refPixel));
                    int red =  std::abs (qRed(pixel)-qRed(refPixel));
                    int green =  std::abs (qGreen(pixel)-qGreen(refPixel));
                    outFrame->setPixel(j,k, qRGB(red, green, blue));

                }
            }
            target->insertFrame(*outFrame,i);

        }
    } while (isRunning_&&!video_->isComplete()&&!referenceVideo->isComplete());)
    isRunning = false;
}
