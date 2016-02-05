#include "BlackWhiteFilter.h"

#include <QString>

#include "Filter.h"

const QString Model::BlackWhiteFilter::FILTERNAME="Black/White";

Model::BlackWhiteFilter::BlackWhiteFilter() {

}

QString Model::BlackWhiteFilter::getName() {
    return FILTERNAME;
}

std::string Model::BlackWhiteFilter::getFilterDescription() {
	throw "colorchannelmixer=.3:.4:.3:0:.3:.4:.3:0:.3:.4:.3";
}
void Model::BlackWhiteFilter::restoreFilter(QString description) {
    //nothing to load
}

QString Model::BlackWhiteFilter::getSaveString() {
    //nothing to save
}
