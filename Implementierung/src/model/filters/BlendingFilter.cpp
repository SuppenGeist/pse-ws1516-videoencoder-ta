#include <exception>
#include <QString>

#include "BlendingFilter.h"
#include "Filter.h"

Model::BlendingFilter::BlendingFilter() {
}

bool Model::BlendingFilter::getInBlend() {
	return this->inBlend;
}

void Model::BlendingFilter::setInBlend(bool inBlend) {
	this->inBlend = inBlend;
}

int Model::BlendingFilter::getStartFrame() {
	return this->startFrame;
}

void Model::BlendingFilter::setStartFrame(int startFrame) {
	this->startFrame = startFrame;
}

int Model::BlendingFilter::getEndFrame() {
	return this->endFrame;
}

void Model::BlendingFilter::setEndFrame(int endFrame) {
	this->endFrame = endFrame;
}

string Model::BlendingFilter::getName() {
	return "Blending";
}

string Model::BlendingFilter::getFilterDescription() {
	throw "Not yet implemented";
}


void Model::BlendingFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::BlendingFilter::getSaveString() {

}
