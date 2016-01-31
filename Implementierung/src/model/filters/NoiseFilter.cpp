#include <exception>
#include <string>

#include "NoiseFilter.h"
#include "../NoiseMode.h"
#include "Filter.h"

Model::NoiseFilter::NoiseFilter() {
}

string Model::NoiseFilter::getFilterDescription() {
	throw "Not yet implemented";
}

Model::NoiseMode Model::NoiseFilter::getMode() {
	throw "Not yet implemented";
}

void Model::NoiseFilter::setMode(NoiseMode mode) {
	throw "Not yet implemented";
}

int Model::NoiseFilter::getIntensity() {
	return this->intensity;
}

string Model::NoiseFilter::getName() {
	return "Noise";
}

void Model::NoiseFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::NoiseFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::NoiseFilter::getSaveString() {

}
