#include "ZoomFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::ZoomFilter::FILTERNAME="Zoom";

Model::ZoomFilter::ZoomFilter() {
}

QString Model::ZoomFilter::getName() {
    return FILTERNAME;
}

std::string Model::ZoomFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::ZoomFilter::getIntensity() {
	return this->intensity;
}

void Model::ZoomFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::ZoomFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setIntensity(list[0].QString::toInt());
}

QString Model::ZoomFilter::getSaveString() {
    QString str = QString::number(intensity);
    return str;
}
