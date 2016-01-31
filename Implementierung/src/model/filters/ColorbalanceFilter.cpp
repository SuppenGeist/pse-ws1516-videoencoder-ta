#include <exception>
#include <string>

#include "ColorbalanceFilter.h"
#include "../../utility/BasicColor.h"
#include "Filter.h"

Model::ColorbalanceFilter::ColorbalanceFilter() {
}

Model::BasicColor Model::ColorbalanceFilter::getColor() {
	throw "Not yet implemented";
}

void Model::ColorbalanceFilter::setColor(BasicColor color) {
	throw "Not yet implemented";
}

int Model::ColorbalanceFilter::getIntensity() {
	return this->intensity;
}

void Model::ColorbalanceFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

bool Model::ColorbalanceFilter::getBrightPixels() {
	return this->brightPixels;
}

void Model::ColorbalanceFilter::setBrightPixels(bool brightPixels) {
	this->brightPixels = brightPixels;
}

bool Model::ColorbalanceFilter::getMediumPixels() {
	return this->mediumPixels;
}

void Model::ColorbalanceFilter::setMediumPixels(bool mediumPixels) {
	this->mediumPixels = mediumPixels;
}

string Model::ColorbalanceFilter::getFilterDescription() {
	throw "Not yet implemented";
}

string Model::ColorbalanceFilter::getName() {
    return "Colorbalance";
}

bool Model::ColorbalanceFilter::getDarkPixels() {
	return this->darkPixels;
}

void Model::ColorbalanceFilter::setDarkPixels(bool darkPixels) {
	this->darkPixels = darkPixels;
}

void Model::ColorbalanceFilter::restoreFilter(QString description){
    throw "Not yet implemented";
}

QString Model::ColorbalanceFilter::getSaveString(){

}
