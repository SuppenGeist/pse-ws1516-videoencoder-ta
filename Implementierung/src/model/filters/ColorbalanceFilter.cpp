/*/*#include <exception>
#include <string>

#include "ColorbalanceFilter.h"
#include "BasicColor.h"
#include "Filter.h"

ColorbalanceFilter::ColorbalanceFilter() {
}

Model::BasicColor ColorbalanceFilter::getColor() {
	throw "Not yet implemented";
}

void ColorbalanceFilter::setColor(BasicColor color) {
	throw "Not yet implemented";
}

int ColorbalanceFilter::getIntensity() {
	return this->intensity;
}

void ColorbalanceFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

bool ColorbalanceFilter::getBrightPixels() {
	return this->brightPixels;
}

void ColorbalanceFilter::setBrightPixels(bool brightPixels) {
	this->brightPixels = brightPixels;
}

bool ColorbalanceFilter::getMediumPixels() {
	return this->mediumPixels;
}

void ColorbalanceFilter::setMediumPixels(bool mediumPixels) {
	this->mediumPixels = mediumPixels;
}

string ColorbalanceFilter::getFilterDescription() {
	throw "Not yet implemented";
}

string ColorbalanceFilter::getName() {
	throw "Not yet implemented";
}

bool ColorbalanceFilter::getDarkPixels() {
	return this->darkPixels;
}

void ColorbalanceFilter::setDarkPixels(bool darkPixels) {
	this->darkPixels = darkPixels;
}

*/

