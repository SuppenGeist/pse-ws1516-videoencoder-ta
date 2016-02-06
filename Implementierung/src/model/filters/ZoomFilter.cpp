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
    std::string str = std::string("zoompan=z='min(zoom+0.0015,");
    str+=std::to_string(intensity);
    str+=")'";
    return str;
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
