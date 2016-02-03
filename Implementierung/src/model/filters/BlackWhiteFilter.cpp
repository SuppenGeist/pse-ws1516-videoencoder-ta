#include <exception>
#include <QString>

#include "BlackWhiteFilter.h"
//#include "../Filter.h"

Model::BlackWhiteFilter::BlackWhiteFilter() {

}

std::string Model::BlackWhiteFilter::getName() {
	return "BlackWhite";
}

std::string Model::BlackWhiteFilter::getFilterDescription() {
    throw "colorchannelmixer=.3:.4:.3:0:.3:.4:.3:0:.3:.4:.3";
}
void Model::BlackWhiteFilter::restoreFilter(QString description) {
//nothing to load
}

QString Model::BlackWhiteFilter::getSaveString() {
    QString str = QString::fromStdString(getName());
    return str;
}
