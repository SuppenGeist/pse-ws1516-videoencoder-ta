#include "ContrastFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::ContrastFilter::FILTERNAME="Contrast";

Model::ContrastFilter::ContrastFilter() {
}

void Model::ContrastFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

int Model::ContrastFilter::getIntensity() {
	return this->intensity;
}

QString Model::ContrastFilter::getName() {
    return FILTERNAME;
}

std::string Model::ContrastFilter::getFilterDescription() {
    std::string str = std::string("eq=");
    str+= "contrast:";
    str+=std::to_string(intensity);
    return str;
}

void Model::ContrastFilter::restoreFilter(QString description) {
    //QStringList list  = description.split(";");
    //setIntensity(list[1].QString::toInt());
}

QString Model::ContrastFilter::getSaveString() {
    QString str(getName());
    str+=";";
    str+=QString::number(intensity);
    return str;
}
