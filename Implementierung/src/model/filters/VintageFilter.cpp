#include <exception>
#include <string>

#include "VintageFilter.h"
#include "Filter.h"

Model::VintageFilter::VintageFilter() {
}

std::string Model::VintageFilter::getName() {
	return "Vintage";
}

std::string Model::VintageFilter::getFilterDescription() {
	std::string str = "curves=vintage";
	return str;
}

void Model::VintageFilter::restoreFilter(QString description) {
//nothing to load
}

QString Model::VintageFilter::getSaveString() {
	QString str = QString::fromStdString(getName());
	return str;
}
