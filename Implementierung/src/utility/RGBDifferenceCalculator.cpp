#include "RGBDifferenceCalculator.h"

#include <memory>

#include "../model/Video.h"

#include <QColor>
#include <QDebug>


Utility::RGBDifferenceCalculator::RGBDifferenceCalculator(Model::Video& referenceVideo,
        Model::Video& video):referenceVideo_(&referenceVideo),video_(&video),isRunning_(false) {
	if(referenceVideo.getWidth()!=video.getWidth()||referenceVideo.getHeight()!=video.getHeight())
		throw std::invalid_argument("Cant calculate psnr of two completly different videos!");
}

Utility::RGBDifferenceCalculator::~RGBDifferenceCalculator() {
	isRunning_=false;
	if(calculator_.joinable())
		calculator_.join();
}

void Utility::RGBDifferenceCalculator::calculateVideo(Model::Video* target) {
	if(!target)
		return;
    target_=target;

	calculator_=std::thread(&RGBDifferenceCalculator::calculateP,this);
}

void Utility::RGBDifferenceCalculator::calculateP() {
	isRunning_ = true;
	std::size_t i=0;
	do {
        for(; i<(video_->getNumberOfFrames()>referenceVideo_->getNumberOfFrames()
                 ?referenceVideo_->getNumberOfFrames():video_->getNumberOfFrames())&&isRunning_; i++) {
			QImage *currentFrame = video_->getFrame(i);
			QImage *refCurrentFrame = referenceVideo_->getFrame(i);
			auto outFrame = std::make_unique<QImage>(currentFrame->width(), currentFrame->height(),
			                currentFrame->format());
			for(int j = 0; j < currentFrame->height(); j++) {
				for(int k = 0; k < currentFrame->width(); k++) {
					auto pixel=currentFrame->pixel(k,j);
					auto refPixel=refCurrentFrame->pixel(k,j);
					int blue =  255-std::abs (qBlue(pixel)-qBlue(refPixel));
					int red =  255-std::abs (qRed(pixel)-qRed(refPixel));
					int green =  255-std::abs (qGreen(pixel)-qGreen(refPixel));
					outFrame->setPixel(k,j, qRgb(red, green, blue));
				}
			}
			target_->appendFrame(std::move(outFrame));
            target_->setFps(video_->getFps());
		}
    } while (isRunning_&&(!video_->isComplete()||!referenceVideo_->isComplete()||i!=(video_->getNumberOfFrames()>referenceVideo_->getNumberOfFrames()?referenceVideo_->getNumberOfFrames():video_->getNumberOfFrames())));
    target_->setIsComplete(true);
	isRunning_ = false;
}
