#include <exception>
#include <string>

#include "BlurFilter.h"
#include "Filter.h"

BlurFilter::BlurFilter() {
}

bool BlurFilter::getPreserveEdges() {
	return this->preserveEdges;
}

void BlurFilter::setPreserveEdges(bool preserveEdges) {
	this->preserveEdges = preserveEdges;
}

int BlurFilter::getIntensity() {
	return this->intensity;
}

void BlurFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

string BlurFilter::getFilterDescription() {
	throw "Not yet implemented";
}

string BlurFilter::getName() {
	throw "Not yet implemented";
}

