#include <exception>
#include <string>

#include "RotationFilter.h"
#include "Filter.h"

Model::RotationFilter::RotationFilter() {
}

std::string Model::RotationFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::RotationFilter::getAngle() {
	return this->angle;
}

std::string Model::RotationFilter::getName() {
	return "Rotation";
}

void Model::RotationFilter::setAngle(int angle) {
	this->angle = angle;
}

void Model::RotationFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::RotationFilter::getSaveString() {

}
