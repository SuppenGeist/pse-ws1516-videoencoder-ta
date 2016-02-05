#include "VintageFilter.h"

#include <QString>

#include "Filter.h"

const QString Model::VintageFilter::FILTERNAME="Vintage";

Model::VintageFilter::VintageFilter() {
}

QString Model::VintageFilter::getName() {
    return FILTERNAME;
}

std::string Model::VintageFilter::getFilterDescription() {
	std::string str = "curves=vintage";
	return str;
}

void Model::VintageFilter::restoreFilter(QString description) {
    //nothing to load
}

QString Model::VintageFilter::getSaveString() {
    QString str(getName());
    return str;
}
