#include <exception>
#include <string>

#include "SaturationFilter.h"
#include "Filter.h"

Model::SaturationFilter::SaturationFilter() {
}

std::string Model::SaturationFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::SaturationFilter::getIntensity() {
	return this->intensity;
}

QString Model::SaturationFilter::getName() {
	return "Saturation";
}

void Model::SaturationFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::SaturationFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::SaturationFilter::getSaveString() {

}
