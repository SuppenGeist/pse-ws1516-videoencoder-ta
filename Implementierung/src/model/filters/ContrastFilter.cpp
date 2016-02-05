#include <exception>
#include <string>

#include "ContrastFilter.h"
#include "Filter.h"

Model::ContrastFilter::ContrastFilter() {
}

void Model::ContrastFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

int Model::ContrastFilter::getIntensity() {
	return this->intensity;
}

QString Model::ContrastFilter::getName() {
	return "Contrast";
}

std::string Model::ContrastFilter::getFilterDescription() {
    std::string str = std::string("eq=");
    str+= "contrast:";
    str+=std::to_string(intensity);
    return str;
}

void Model::ContrastFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setIntensity(list[1].QString::toInt());
}

QString Model::ContrastFilter::getSaveString() {
    QString str = QString(getName());
    str+=";";
    str+=QString::number(intensity);
    return str;
}
