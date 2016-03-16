#include "PsnrCalculator.h"

#include <QDebug>

#include <stdexcept>
#include <cmath>

#include "../model/Video.h"
#include "../model/Graph.h"

Utility::PsnrCalculator::PsnrCalculator(Model::Video& referenceVideo,
                                        Model::Video& compareVideo):referenceVideo_(&referenceVideo),video_(&compareVideo) {
	if(referenceVideo.getWidth()!=compareVideo.getWidth()
	        || referenceVideo.getHeight()!=compareVideo.getHeight()) {
		throw std::invalid_argument("Cant calculate psnr of two completly different videos!");
	}
}

Utility::PsnrCalculator::~PsnrCalculator() {
	isRunning_=false;
	if(calculator_.joinable())
		calculator_.join();
}

void Utility::PsnrCalculator::calculate(Model::Graph *target) {
	if(!target)
		return;
	target_=target;

	calculator_=std::thread(&PsnrCalculator::calculateP,this);
}

double Utility::PsnrCalculator::calculateMeanSquareError(QImage *frame1, QImage *frame2) {
	double mse=0;
	int diffR=0;
	int diffG=0;
	int diffB=0;

	int width=frame1->width();
	int height=frame1->height();

	for(int k=0; k<width; k++) {
		for(int j=0; j<height; j++) {
			auto color1=frame1->pixel(k,j);
			auto color2=frame2->pixel(k,j);

			diffR=qRed(color1)-qRed(color2);
			diffG=qGreen(color1)-qGreen(color2);
			diffB=qBlue(color1)-qBlue(color2);

			mse+=diffR*diffR+diffG*diffG+diffB*diffB;
		}
	}

	mse=mse/(width*height);
	mse=mse/3;

	return mse;
}

void Utility::PsnrCalculator::calculateP() {
	isRunning_=true;
	std::size_t i=0;
	do {
		for(; (i<(video_->getNumberOfFrames()>referenceVideo_->getNumberOfFrames()
		          ?referenceVideo_->getNumberOfFrames():video_->getNumberOfFrames()))&&isRunning_; i++) {
			double psnr=-1;
			double mse=calculateMeanSquareError(referenceVideo_->getFrame(i),video_->getFrame(i));
			if(mse!=0) {
				psnr=10.0*std::log10(65025/mse);
			}
			target_->setValue(i,psnr);
		}
	} while(isRunning_&&(!video_->isComplete()||!referenceVideo_->isComplete()
	                     ||i!=(video_->getNumberOfFrames()>referenceVideo_->getNumberOfFrames()
	                           ?referenceVideo_->getNumberOfFrames():video_->getNumberOfFrames())));
	isRunning_=false;
}
