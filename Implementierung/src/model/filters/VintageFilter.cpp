#include "VintageFilter.h"

#include <QString>

#include "Filter.h"

const QString Model::VintageFilter::FILTERNAME="Vintage";

Model::VintageFilter::VintageFilter() {

}

QString Model::VintageFilter::getName() const {
	return FILTERNAME;
}

std::string Model::VintageFilter::getFilterDescription() {
	return "curves=r='0/0,11 ,42/,51 1/0,95':g='0,50/0,48':b='0/0,22 ,49/,44 1/0,8'";
}

void Model::VintageFilter::restore(QString description) {
	//nothing to load
}

QString Model::VintageFilter::getSaveString() const {
	return "";
}
