#include <exception>
#include <string>

#include "BrightnessFilter.h"
#include "Filter.h"

Model::BrightnessFilter::BrightnessFilter() {
}

int Model::BrightnessFilter::getIntensity() {
	return this->intensity;
}

void Model::BrightnessFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

std::string Model::BrightnessFilter::getName() {
	return "Brightness";
}

std::string Model::BrightnessFilter::getFilterDescription() {
	throw "Not yet implemented";
}

void Model::BrightnessFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::BrightnessFilter::getSaveString() {

}
