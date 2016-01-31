#include <exception>
#include <string>

#include "NegativeFilter.h"
#include "Filter.h"

Model::NegativeFilter::NegativeFilter() {
}

std::string Model::NegativeFilter::getFilterDescription() {
	throw "Not yet implemented";
}

<<<<<<< HEAD
std::string Model::NegativeFilter::getName() {
    return "Negative";
=======
string Model::NegativeFilter::getName() {
	return "Negative";
>>>>>>> origin/master
}

void Model::NegativeFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::NegativeFilter::getSaveString() {

}
