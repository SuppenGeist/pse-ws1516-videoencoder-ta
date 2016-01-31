#include <exception>
#include <string>

#include "ZoomFilter.h"
#include "Filter.h"

Model::ZoomFilter::ZoomFilter() {
}

string Model::ZoomFilter::getName() {
    return "Zoom";
}

string Model::ZoomFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::ZoomFilter::getIntensity() {
	return this->intensity;
}

void Model::ZoomFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::ZoomFilter::restoreFilter(string description){
    throw "Not yet implemented";
}
