#include <exception>
#include <string>

#include "ZoomFilter.h"
#include "Filter.h"

Model::ZoomFilter::ZoomFilter() {
}

QString Model::ZoomFilter::getName() {
	return "Zoom";
}

std::string Model::ZoomFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::ZoomFilter::getIntensity() {
	return this->intensity;
}

void Model::ZoomFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::ZoomFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::ZoomFilter::getSaveString() {

}
