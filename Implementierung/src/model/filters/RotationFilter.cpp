#include <exception>
#include <string>

#include "RotationFilter.h"
#include "Filter.h"

Model::RotationFilter::RotationFilter() {
}

string Model::RotationFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::RotationFilter::getAngle() {
	return this->angle;
}

string Model::RotationFilter::getName() {
    return "Rotation";
}

void Model::RotationFilter::setAngle(int angle) {
	this->angle = angle;
}

void Model::RotationFilter::restoreFilter(string description){
    throw "Not yet implemented";
}
