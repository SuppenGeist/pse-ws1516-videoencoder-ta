
#include <string>

#include "EdgeFilter.h"
#include "Filter.h"

Model::EdgeFilter::EdgeFilter() {
}

std::string Model::EdgeFilter::getFilterDescription() {
	throw "Not yet implemented";
}

std::string Model::EdgeFilter::getName() {
	return "Edge";
}

void Model::EdgeFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::EdgeFilter::getSaveString() {

}
