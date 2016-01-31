#include <exception>
#include <string>

#include "ZoomFilter.h"
#include "Filter.h"

Model::ZoomFilter::ZoomFilter() {
}

<<<<<<< HEAD
std::string Model::ZoomFilter::getName() {
    return "Zoom";
=======
string Model::ZoomFilter::getName() {
	return "Zoom";
>>>>>>> origin/master
}

std::string Model::ZoomFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::ZoomFilter::getIntensity() {
	return this->intensity;
}

void Model::ZoomFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::ZoomFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::ZoomFilter::getSaveString() {

}
