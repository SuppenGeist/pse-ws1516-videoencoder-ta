/*/*#include <exception>
#include <string>

#include "SharpnessFilter.h"
#include "Filter.h"

SharpnessFilter::SharpnessFilter() {
}

string SharpnessFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int SharpnessFilter::getIntensity() {
	return this->intensity;
}

string SharpnessFilter::getName() {
	throw "Not yet implemented";
}

void SharpnessFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

*/
