#include "SaturationFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::SaturationFilter::FILTERNAME="Saturation";

Model::SaturationFilter::SaturationFilter() {
}

std::string Model::SaturationFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::SaturationFilter::getIntensity() {
	return this->intensity;
}

QString Model::SaturationFilter::getName() {
    return FILTERNAME;
}

void Model::SaturationFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::SaturationFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setIntensity(list[1].QString::toInt());
}

QString Model::SaturationFilter::getSaveString() {
    QString str(getName());
    str+=";";
    str+=QString::number(intensity);
    return str;

}
