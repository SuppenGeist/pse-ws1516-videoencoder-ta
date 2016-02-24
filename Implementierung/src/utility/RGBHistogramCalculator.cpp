#include "RGBHistogramCalculator.h"

#include <memory>

#include "../model/Video.h"
#include "../model/Graph.h"
#include "../model/graphvideo.h"

#include <QColor>
#include <QDebug>

Utility::RGBHistogramCalculator::RGBHistogramCalculator(Model::Video& video) {
	video_ = &video;
}

Utility::RGBHistogramCalculator::~RGBHistogramCalculator() {
	isRunning_=false;
	if(calculator_.joinable()) {
		calculator_.join();
	}
}

void Utility::RGBHistogramCalculator::calculate(Model::GraphVideo *targetRed,
        Model::GraphVideo *targetGreen, Model::GraphVideo *targetBlue) {
	if(!targetBlue||!targetGreen||!targetRed)
		return;

	red_=targetRed;
	blue_=targetBlue;
	green_=targetGreen;
	red_->setFps(video_->getFps());
	green_->setFps(video_->getFps());
	blue_->setFps(video_->getFps());

	calculator_=std::thread(&RGBHistogramCalculator::calculateP,this);
}

void Utility::RGBHistogramCalculator::calculateP() {
	isRunning_=true;
	std::size_t i=0;
	do {
		for(; i < video_->getNumberOfFrames()&&isRunning_; i++) {
			QImage *currentFrame = video_->getFrame(i);

			auto redg=std::make_unique<Model::Graph>();
			auto greeng=std::make_unique<Model::Graph>();
			auto blueg=std::make_unique<Model::Graph>();

			for(int j = 0; j < currentFrame->height(); j++) {
				for(int k = 0; k < currentFrame->width(); k++) {
					auto pixel=currentFrame->pixel(k,j);
					int blue=qBlue(pixel);
					blueg->setValue(blue,blueg->getValue(blue)+1);

					int red=qRed(pixel);
					redg->setValue(red,redg->getValue(red)+1);

					int green=qGreen(pixel);
					greeng->setValue(green,greeng->getValue(green)+1);
				}
			}

			for(int k=0; k<256; k++) {
				blueg->setValue(k,blueg->getValue(k)+1);
				redg->setValue(k,redg->getValue(k)+1);
				greeng->setValue(k,greeng->getValue(k)+1);
			}

			red_->appendGraph(std::move(redg));
			green_->appendGraph(std::move(greeng));
			blue_->appendGraph(std::move(blueg));
		}
	} while (isRunning_&&!video_->isComplete());
	red_->setIsComplete(true);
	green_->setIsComplete(true);
	blue_->setIsComplete(true);
	isRunning_=false;
}
