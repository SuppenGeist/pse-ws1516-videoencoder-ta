#include <exception>
#include <string>

#include "NegativeFilter.h"
#include "Filter.h"

Model::NegativeFilter::NegativeFilter() {
}

std::string Model::NegativeFilter::getFilterDescription() {
	throw "Not yet implemented";
}

std::string Model::NegativeFilter::getName() {
	return "Negative";
}

void Model::NegativeFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::NegativeFilter::getSaveString() {

}
