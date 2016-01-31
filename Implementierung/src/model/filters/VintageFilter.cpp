#include <exception>
#include <string>

#include "VintageFilter.h"
#include "Filter.h"

Model::VintageFilter::VintageFilter() {
}

<<<<<<< HEAD
std::string Model::VintageFilter::getName() {
    return "Vintage";
}

std::string Model::VintageFilter::getFilterDescription() {
    std::string str = "curves=vintage";
    return str;
=======
string Model::VintageFilter::getName() {
	return "Vintage";
}

string Model::VintageFilter::getFilterDescription() {
	string str = "curves=vintage";
	return str;
>>>>>>> origin/master
}

void Model::VintageFilter::restoreFilter(QString description) {
//nothing to save
}

QString Model::VintageFilter::getSaveString() {
//nothing to save
}
