#include <exception>
#include <string>

#include "BlurFilter.h"
#include "Filter.h"

Model::BlurFilter::BlurFilter() {
}

bool Model::BlurFilter::getPreserveEdges() {
	return this->preserveEdges;
}

void Model::BlurFilter::setPreserveEdges(bool preserveEdges) {
	this->preserveEdges = preserveEdges;
}

int Model::BlurFilter::getIntensity() {
	return this->intensity;
}

void Model::BlurFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

std::string Model::BlurFilter::getFilterDescription() {
	throw "Not yet implemented";
}

<<<<<<< HEAD
std::string Model::BlurFilter::getName() {
    return "Blur";
=======
string Model::BlurFilter::getName() {
	return "Blur";
>>>>>>> origin/master
}

void Model::BlurFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::BlurFilter::getSaveString() {

}
