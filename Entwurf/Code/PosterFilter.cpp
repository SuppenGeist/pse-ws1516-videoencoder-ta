#include <exception>
#include <string>

#include "PosterFilter.h"
#include "Filter.h"

PosterFilter::PosterFilter() {
}

string PosterFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int PosterFilter::getNumberOfColors() {
	return this->numberOfColors;
}

string PosterFilter::getName() {
	throw "Not yet implemented";
}

void PosterFilter::setNumberOfColors(int numberOfColors) {
	this->numberOfColors = numberOfColors;
}

