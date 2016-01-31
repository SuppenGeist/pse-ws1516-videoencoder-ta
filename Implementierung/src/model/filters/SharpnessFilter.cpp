#include <exception>
#include <string>

#include "SharpnessFilter.h"
#include "Filter.h"

Model::SharpnessFilter::SharpnessFilter() {
}

string Model::SharpnessFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::SharpnessFilter::getIntensity() {
	return this->intensity;
}

string Model::SharpnessFilter::getName() {
    return "Sharpness";
}

void Model::SharpnessFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::SharpnessFilter::restoreFilter(QString description){
    throw "Not yet implemented";
}

QString Model::SharpnessFilter::getSaveString(){

}
