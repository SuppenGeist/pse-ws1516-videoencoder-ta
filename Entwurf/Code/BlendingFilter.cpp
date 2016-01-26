#include <exception>
#include <string>

#include "BlendingFilter.h"
#include "Filter.h"

BlendingFilter::BlendingFilter() {
}

bool BlendingFilter::getInBlend() {
	return this->inBlend;
}

void BlendingFilter::setInBlend(bool inBlend) {
	this->inBlend = inBlend;
}

int BlendingFilter::getStartFrame() {
	return this->startFrame;
}

void BlendingFilter::setStartFrame(int startFrame) {
	this->startFrame = startFrame;
}

int BlendingFilter::getEndFrame() {
	return this->endFrame;
}

void BlendingFilter::setEndFrame(int endFrame) {
	this->endFrame = endFrame;
}

string BlendingFilter::getName() {
	throw "Not yet implemented";
}

string BlendingFilter::getFilterDescription() {
	throw "Not yet implemented";
}

