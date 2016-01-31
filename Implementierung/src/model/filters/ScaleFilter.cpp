#include <exception>
#include <string>

#include "ScaleFilter.h"
#include "Filter.h"

Model::ScaleFilter::ScaleFilter() {
}

string Model::ScaleFilter::getFilterDescription() {
	throw "Not yet implemented";
}

bool Model::ScaleFilter::getKeepRatio() {
	return this->keepRatio;
}

void Model::ScaleFilter::setKeepRatio(bool keepRatio) {
	this->keepRatio = keepRatio;
}

string Model::ScaleFilter::getName() {
    return "Scale";
}

int Model::ScaleFilter::getWidth() {
	return this->width;
}

void Model::ScaleFilter::setWidth(int width) {
	this->width = width;
}

int Model::ScaleFilter::getHeight() {
	return this->height;
}

void Model::ScaleFilter::setHeight(int height) {
	this->height = height;
}

int Model::ScaleFilter::getRatio() {
	return this->ratio;
}

void Model::ScaleFilter::setRatio(int ratio) {
	this->ratio = ratio;
}

void Model::ScaleFilter::restoreFilter(string description){
    throw "Not yet implemented";
}
