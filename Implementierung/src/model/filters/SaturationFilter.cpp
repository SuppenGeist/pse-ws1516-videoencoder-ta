#include "SaturationFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::SaturationFilter::FILTERNAME="Saturation";

Model::SaturationFilter::SaturationFilter() {
}

std::string Model::SaturationFilter::getFilterDescription() {
    std::string str = std::string("eq=");
    str+= "saturation";
    str+=std::to_string(intensity);
    return str;
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
    setIntensity(list[0].QString::toInt());
}

QString Model::SaturationFilter::getSaveString() {
    QString str = QString::number(intensity);
    return str;

}
