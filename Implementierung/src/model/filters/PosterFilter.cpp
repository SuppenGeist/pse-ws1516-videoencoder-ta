#include <exception>
#include <string>

#include "PosterFilter.h"
#include "Filter.h"

Model::PosterFilter::PosterFilter() {
}

std::string Model::PosterFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::PosterFilter::getNumberOfColors() {
	return this->numberOfColors;
}

QString Model::PosterFilter::getName() {
	return "Poster";
}

void Model::PosterFilter::setNumberOfColors(int numberOfColors) {
	this->numberOfColors = numberOfColors;
}

void Model::PosterFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::PosterFilter::getSaveString() {

}
