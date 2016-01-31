#include <exception>
#include <string>

#include "PosterFilter.h"
#include "Filter.h"

Model::PosterFilter::PosterFilter() {
}

<<<<<<< HEAD
std::string Model::PosterFilter::getFilterDescription() {
    throw "Not yet implemented";
=======
string Model::PosterFilter::getFilterDescription() {
	throw "Not yet implemented";
>>>>>>> origin/master
}

int Model::PosterFilter::getNumberOfColors() {
	return this->numberOfColors;
}

<<<<<<< HEAD
std::string Model::PosterFilter::getName() {
    return "Poster";
=======
string Model::PosterFilter::getName() {
	return "Poster";
>>>>>>> origin/master
}

void Model::PosterFilter::setNumberOfColors(int numberOfColors) {
	this->numberOfColors = numberOfColors;
}

void Model::PosterFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::PosterFilter::getSaveString() {

}
