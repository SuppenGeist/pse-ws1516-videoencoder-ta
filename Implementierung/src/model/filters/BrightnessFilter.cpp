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

string Model::BrightnessFilter::getName() {
    return "Brightness";
}

string Model::BrightnessFilter::getFilterDescription() {
	throw "Not yet implemented";
}



