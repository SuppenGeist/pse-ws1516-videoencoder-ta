#include "RGBHistogrammCalculator.h"
#include "../model/Video.h"
#include "../model/Graph.h"
#include <QColor>

Utility::RGBHistogrammCalculator::RGBHistogrammCalculator(Model::Video& video) {
	this->video = &video;
	this->blueHistogramm = new Model::Graph();
	this->greenHistogramm = new Model::Graph();
	this->redHistogramm = new Model::Graph();
}

void Utility::RGBHistogrammCalculator::calculate() {
	for(int i = 0; i < video->getNumberOfFrames(); i++) {
		QImage *currentFrame = video->getFrame(i);
		int blueChannel, redChannel, greenChannel;
		for(int j = 0; i < currentFrame->height(); j++) {
			for(int k = 0; k < currentFrame->width(); k++) {
				blueChannel += qBlue(currentFrame->pixel(j,k));
				redChannel += qRed(currentFrame->pixel(j,k));
				greenChannel += qGreen(currentFrame->pixel(j,k));
			}
		}
		redHistogramm->setValue(i, redChannel / (currentFrame->height() * currentFrame->width()));
		blueHistogramm->setValue(i, blueChannel / (currentFrame->height() * currentFrame->width()));
		greenHistogramm->setValue(i, greenChannel / (currentFrame->height() * currentFrame->width()));
	}
}

Model::Graph* Utility::RGBHistogrammCalculator::getRedHistogramm() {
	return this->redHistogramm;
}

Model::Graph* Utility::RGBHistogrammCalculator::getGreenHistogramm() {
	return this->greenHistogramm;
}

Model::Graph* Utility::RGBHistogrammCalculator::getBlueHistogramm() {
	return this->blueHistogramm;
}
