#include "NegativeFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::NegativeFilter::FILTERNAME="Negative";

Model::NegativeFilter::NegativeFilter() {
}

std::string Model::NegativeFilter::getFilterDescription() {
	return "negate";
}

QString Model::NegativeFilter::getName() const {
	return FILTERNAME;
}

void Model::NegativeFilter::restore(QString description) {
	//nothing to load
}

QString Model::NegativeFilter::getSaveString() const {
	//nothing to save
}
