#include "SepiaFilter.h"

#include <QString>

#include "Filter.h"

const QString Model::SepiaFilter::FILTERNAME="Sepia";

Model::SepiaFilter::SepiaFilter() {
}

QString Model::SepiaFilter::getName() {
    return FILTERNAME;
}

std::string Model::SepiaFilter::getFilterDescription() {
	std::string str = "colorchannelmixer=.393:.769:.189:0:.349:.686:.168:0:.272:.534:.131";
	return str;
}

void Model::SepiaFilter::restoreFilter(QString description) {
    //nothing to load
}

QString Model::SepiaFilter::getSaveString() {
    QString str(getName());
    return str;
}
