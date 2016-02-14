#include "EdgeFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::EdgeFilter::FILTERNAME="Edge";

Model::EdgeFilter::EdgeFilter() {
}

std::string Model::EdgeFilter::getFilterDescription() {
	return "edgedetect";
}

QString Model::EdgeFilter::getName() const {
	return FILTERNAME;
}

void Model::EdgeFilter::restore(QString description) {
	//nothing to load
}

QString Model::EdgeFilter::getSaveString() const {
	return "";
}
