#include "SharpnessFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::SharpnessFilter::FILTERNAME="Sharpness";

Model::SharpnessFilter::SharpnessFilter() {
}

std::string Model::SharpnessFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::SharpnessFilter::getIntensity() {
	return this->intensity;
}

QString Model::SharpnessFilter::getName() {
    return FILTERNAME;
}

void Model::SharpnessFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::SharpnessFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setIntensity(list[0].QString::toInt());
}

QString Model::SharpnessFilter::getSaveString() {
    QString str = QString::number(intensity);
    return str;
}
