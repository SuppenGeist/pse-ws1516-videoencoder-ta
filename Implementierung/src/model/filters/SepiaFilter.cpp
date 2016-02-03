#include <exception>
#include <string>

#include "SepiaFilter.h"
#include "Filter.h"

Model::SepiaFilter::SepiaFilter() {
}

std::string Model::SepiaFilter::getName() {
	return "Sepia";
}

std::string Model::SepiaFilter::getFilterDescription() {
    std::string str = "colorchannelmixer=.393:.769:.189:0:.349:.686:.168:0:.272:.534:.131";
	return str;
}

void Model::SepiaFilter::restoreFilter(QString description) {
//nothing to save
}

QString Model::SepiaFilter::getSaveString() {
    QString str = QString::fromStdString(getName());
    return str;
}
