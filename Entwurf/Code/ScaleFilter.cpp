#include <exception>
#include <string>

#include "ScaleFilter.h"
#include "Filter.h"

ScaleFilter::ScaleFilter() {
}

string ScaleFilter::getFilterDescription() {
	throw "Not yet implemented";
}

bool ScaleFilter::getKeepRatio() {
	return this->keepRatio;
}

void ScaleFilter::setKeepRatio(bool keepRatio) {
	this->keepRatio = keepRatio;
}

string ScaleFilter::getName() {
	throw "Not yet implemented";
}

int ScaleFilter::getWidth() {
	return this->width;
}

void ScaleFilter::setWidth(int width) {
	this->width = width;
}

int ScaleFilter::getHeight() {
	return this->height;
}

void ScaleFilter::setHeight(int height) {
	this->height = height;
}

int ScaleFilter::getRatio() {
	return this->ratio;
}

void ScaleFilter::setRatio(int ratio) {
	this->ratio = ratio;
}

