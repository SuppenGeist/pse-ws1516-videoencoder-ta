#include "SaturationFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::SaturationFilter::FILTERNAME="Saturation";

Model::SaturationFilter::SaturationFilter(): intensity_(50) {
}

std::string Model::SaturationFilter::getFilterDescription() {
	std::string str = std::string("eq=contrast=1:brightness=0:saturation='");	
    str+=std::to_string((double)intensity_/33);
	str+="':gamma=1:gamma_r=1:gamma_g=1:gamma_b=1:gamma_weight=1";
	return str;
}

int Model::SaturationFilter::getIntensity() {
	return intensity_;
}

QString Model::SaturationFilter::getName() const {
	return FILTERNAME;
}

void Model::SaturationFilter::setIntensity(int intensity) {
    if(intensity<0||intensity>100)
        return;
	intensity_ = intensity;
}

void Model::SaturationFilter::restore(QString description) {
	QStringList list  = description.split(";");
    if(list.size()!=1)
        return;
	setIntensity(list[0].QString::toInt());
}

QString Model::SaturationFilter::getSaveString() const {
	QString str = QString::number(intensity_);
	return str;

}
