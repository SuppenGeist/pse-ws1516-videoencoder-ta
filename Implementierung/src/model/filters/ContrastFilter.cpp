#include "ContrastFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::ContrastFilter::FILTERNAME="Contrast";

Model::ContrastFilter::ContrastFilter():intensity_(80) {

}

void Model::ContrastFilter::setIntensity(int intensity) {
	if(intensity<-100||intensity>100)
		return;
	intensity_ = intensity;
}

int Model::ContrastFilter::getIntensity() {
	return intensity_;
}

QString Model::ContrastFilter::getName() const {
	return FILTERNAME;
}

std::string Model::ContrastFilter::getFilterDescription() {
	std::string str = std::string("eq=contrast='"+std::to_string((double)intensity_/50)
	                              +"':brightness=0:saturation=1:gamma=1:gamma_r=1:gamma_g=1:gamma_b=1:gamma_weight=1");

	return str;
}

void Model::ContrastFilter::restore(QString description) {
	QStringList list  = description.split(";");
	if(list.size()!=1)
		return;
	setIntensity(list[0].QString::toInt());
}

QString Model::ContrastFilter::getSaveString() const {
	QString str = QString::number(intensity_);

	return str;
}
