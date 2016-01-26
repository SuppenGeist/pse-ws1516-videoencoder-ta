#include <exception>
#include <string>

#include "ZoomFilter.h"
#include "Filter.h"

ZoomFilter::ZoomFilter() {
}

string ZoomFilter::getName() {
	throw "Not yet implemented";
}

string ZoomFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int ZoomFilter::getIntensity() {
	return this->intensity;
}

void ZoomFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

