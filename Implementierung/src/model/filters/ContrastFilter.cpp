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

<<<<<<< HEAD
std::string Model::ContrastFilter::getName() {
    return "Contrast";
=======
string Model::ContrastFilter::getName() {
	return "Contrast";
>>>>>>> origin/master
}

std::string Model::ContrastFilter::getFilterDescription() {
	throw "Not yet implemented";
}

void Model::ContrastFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::ContrastFilter::getSaveString() {

}
