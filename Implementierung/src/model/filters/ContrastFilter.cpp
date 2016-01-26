#include <exception>
#include <string>

#include "ContrastFilter.h"
#include "Filter.h"

ContrastFilter::ContrastFilter() {
}

void ContrastFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

int ContrastFilter::getIntensity() {
	return this->intensity;
}

string ContrastFilter::getName() {
	throw "Not yet implemented";
}

string ContrastFilter::getFilterDescription() {
	throw "Not yet implemented";
}

