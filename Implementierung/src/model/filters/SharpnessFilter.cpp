#include <exception>
#include <string>

#include "SharpnessFilter.h"
#include "Filter.h"

Model::SharpnessFilter::SharpnessFilter() {
}

std::string Model::SharpnessFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::SharpnessFilter::getIntensity() {
	return this->intensity;
}

<<<<<<< HEAD
std::string Model::SharpnessFilter::getName() {
    return "Sharpness";
=======
string Model::SharpnessFilter::getName() {
	return "Sharpness";
>>>>>>> origin/master
}

void Model::SharpnessFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::SharpnessFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::SharpnessFilter::getSaveString() {

}
