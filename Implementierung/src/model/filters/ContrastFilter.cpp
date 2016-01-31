#include <exception>
#include <string>

#include "ContrastFilter.h"
#include "Filter.h"

Model::ContrastFilter::ContrastFilter() {
}

void Model::ContrastFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

int Model::ContrastFilter::getIntensity() {
	return this->intensity;
}

string Model::ContrastFilter::getName() {
    return "Contrast";
}

string Model::ContrastFilter::getFilterDescription() {
	throw "Not yet implemented";
}

void Model::ContrastFilter::restoreFilter(string description){
    throw "Not yet implemented";
}

