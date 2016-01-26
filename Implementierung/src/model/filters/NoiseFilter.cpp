/*/*#include <exception>
#include <string>

#include "NoiseFilter.h"
#include "NoiseMode.h"
#include "Filter.h"

NoiseFilter::NoiseFilter() {
}

string NoiseFilter::getFilterDescription() {
	throw "Not yet implemented";
}

Model::NoiseMode NoiseFilter::getMode() {
	throw "Not yet implemented";
}

void NoiseFilter::setMode(NoiseMode mode) {
	throw "Not yet implemented";
}

int NoiseFilter::getIntensity() {
	return this->intensity;
}

string NoiseFilter::getName() {
	throw "Not yet implemented";
}

void NoiseFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

*/
