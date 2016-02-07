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
    return "curves=preset=vintage";
}

void Model::VintageFilter::restoreFilter(QString description) {
    //nothing to load
}

QString Model::VintageFilter::getSaveString() {
    //nothing to save
}
