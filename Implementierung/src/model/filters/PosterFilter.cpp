#include <exception>
#include <string>

#include "PosterFilter.h"
#include "Filter.h"

Model::PosterFilter::PosterFilter() {
}

string Model::PosterFilter::getFilterDescription() {
    throw "Not yet implemented";
}

int Model::PosterFilter::getNumberOfColors() {
	return this->numberOfColors;
}

string Model::PosterFilter::getName() {
    return "Poster";
}

void Model::PosterFilter::setNumberOfColors(int numberOfColors) {
	this->numberOfColors = numberOfColors;
}


