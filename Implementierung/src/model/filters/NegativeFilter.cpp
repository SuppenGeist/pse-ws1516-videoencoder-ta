#include "NegativeFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::NegativeFilter::FILTERNAME="Negative";

Model::NegativeFilter::NegativeFilter() {
}

std::string Model::NegativeFilter::getFilterDescription() {
	throw "Not yet implemented";
}

QString Model::NegativeFilter::getName() {
    return FILTERNAME;
}

void Model::NegativeFilter::restoreFilter(QString description) {
    //nothing to load
}

QString Model::NegativeFilter::getSaveString() {
    QString str(getName());
    return str;
}
