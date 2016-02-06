#include "Grayscale.h"

#include <QString>

#include <string>

#include "Filter.h"

const QString Model::Grayscale::FILTERNAME="Grayscale";

Model::Grayscale::Grayscale() {

}

QString Model::Grayscale::getName() {
    return FILTERNAME;
}

std::string Model::Grayscale::getFilterDescription() {
    return "null";
}
void Model::Grayscale::restoreFilter(QString description) {
    //nothing to load
}

QString Model::Grayscale::getSaveString() {
    //nothing to save
}
