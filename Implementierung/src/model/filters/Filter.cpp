#include <exception>
#include <string>

#include "Filter.h"
//#include "RemoveFilter.h"


std::string Model::Filter::getName() {
	return "Filter";
}

std::string Model::Filter::getFilterDescription() {
	throw "Not yet implemented";
}

void Model::Filter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::Filter::getSaveString() {

}
