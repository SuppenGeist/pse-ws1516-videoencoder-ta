#include "GrayscaleFilter.h"

#include <QString>

#include <string>

#include "Filter.h"

const QString Model::GrayscaleFilter::FILTERNAME="Grayscale";

Model::GrayscaleFilter::GrayscaleFilter() {

}

QString Model::GrayscaleFilter::getName() {
    return FILTERNAME;
}

std::string Model::GrayscaleFilter::getFilterDescription() {
    return "lutyuv=u=128:v=128";
}
void Model::GrayscaleFilter::restoreFilter(QString description) {
    //nothing to load
}

QString Model::GrayscaleFilter::getSaveString() {
    //nothing to save
}
