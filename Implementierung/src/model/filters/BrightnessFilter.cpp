#include "BrightnessFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::BrightnessFilter::FILTERNAME="Brightness";

Model::BrightnessFilter::BrightnessFilter():intensity_(20) {

}

int Model::BrightnessFilter::getIntensity() {
	return intensity_;
}

void Model::BrightnessFilter::setIntensity(int intensity) {
	if(intensity<-100||intensity>100)
		return;
	intensity_ = intensity;
}

QString Model::BrightnessFilter::getName() const {
	return FILTERNAME;
}

std::string Model::BrightnessFilter::getFilterDescription() {
	std::string str = std::string("eq=contrast=1:brightness='"+std::to_string((
	                                  double)intensity_/100)+"':saturation=1:gamma=1:gamma_r=1:gamma_g=1:gamma_b=1:gamma_weight=1");

	return str;
}

void Model::BrightnessFilter::restore(QString description) {
	QStringList list  = description.split(";");
	if(list.size()!=1)
		return;
	setIntensity(list[0].QString::toInt());
}

QString Model::BrightnessFilter::getSaveString() const {
	QString str =QString::number(intensity_);

	return str;
}
