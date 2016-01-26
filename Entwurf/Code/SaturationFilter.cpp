#include <exception>
#include <string>

#include "SaturationFilter.h"
#include "Filter.h"

SaturationFilter::SaturationFilter() {
}

string SaturationFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int SaturationFilter::getIntensity() {
	return this->intensity;
}

string SaturationFilter::getName() {
	throw "Not yet implemented";
}

void SaturationFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

