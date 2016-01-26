#include <exception>
#include <string>

#include "BrightnessFilter.h"
#include "Filter.h"

BrightnessFilter::BrightnessFilter() {
}

int BrightnessFilter::getIntensity() {
	return this->intensity;
}

void BrightnessFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

string BrightnessFilter::getName() {
	throw "Not yet implemented";
}

string BrightnessFilter::getFilterDescription() {
	throw "Not yet implemented";
}

