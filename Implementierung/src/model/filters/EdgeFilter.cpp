#include "EdgeFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::EdgeFilter::FILTERNAME="Edge";

Model::EdgeFilter::EdgeFilter() {
}

std::string Model::EdgeFilter::getFilterDescription() {
	throw "Not yet implemented";
}

QString Model::EdgeFilter::getName() {
    return FILTERNAME;
}

void Model::EdgeFilter::restoreFilter(QString description) {
    //nothing to load
}

QString Model::EdgeFilter::getSaveString() {
    //nothing to save
}
