#include <exception>
#include <QString>
#include <QStringList>

#include "BrightnessFilter.h"
#include "Filter.h"

Model::BrightnessFilter::BrightnessFilter() {
}

int Model::BrightnessFilter::getIntensity() {
	return this->intensity;
}

void Model::BrightnessFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

std::string Model::BrightnessFilter::getName() {
	return "Brightness";
}

std::string Model::BrightnessFilter::getFilterDescription() {
    std::string str = std::string("eq=contrast=1:");
    str+= "brightness";
    str+=std::to_string(intensity);
    return str;
}

void Model::BrightnessFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setIntensity(list[1].QString::toInt());
}

QString Model::BrightnessFilter::getSaveString() {
    QString str = QString::fromStdString(getName());
    str+=";";
    str+=QString::number(intensity);
    return str;
}
