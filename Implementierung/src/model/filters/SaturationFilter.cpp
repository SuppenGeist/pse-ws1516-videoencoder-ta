#include "SaturationFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::SaturationFilter::FILTERNAME="Saturation";

Model::SaturationFilter::SaturationFilter(): intensity_(50) {
}

std::string Model::SaturationFilter::getFilterDescription() {
	std::string str = std::string("eq=contrast=1:brightness=0:saturation='");
	if(intensity_<0) {
		str+="0";
	} else {
		str+=std::to_string((double)intensity_/33);
	}
	str+="':gamma=1:gamma_r=1:gamma_g=1:gamma_b=1:gamma_weight=1";
	return str;
}

int Model::SaturationFilter::getIntensity() {
	return intensity_;
}

QString Model::SaturationFilter::getName() {
	return FILTERNAME;
}

void Model::SaturationFilter::setIntensity(int intensity) {
	intensity_ = intensity;
}

void Model::SaturationFilter::restoreFilter(QString description) {
	QStringList list  = description.split(";");
	setIntensity(list[0].QString::toInt());
}

QString Model::SaturationFilter::getSaveString() {
	QString str = QString::number(intensity_);
	return str;

}
