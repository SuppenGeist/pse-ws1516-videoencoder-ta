#include "SharpnessFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::SharpnessFilter::FILTERNAME="Sharpness";

Model::SharpnessFilter::SharpnessFilter(): intensity_(60) {
}

std::string Model::SharpnessFilter::getFilterDescription() {
	std::string str = std::string("unsharp=la=");
	if(intensity_<0) {
		str+=std::to_string((int)((double)intensity_/100*2));
	} else {
		str+=std::to_string((int)((double)intensity_/100*5));
	}
	return str;
}

int Model::SharpnessFilter::getIntensity() {
	return intensity_;
}

QString Model::SharpnessFilter::getName() const {
	return FILTERNAME;
}

void Model::SharpnessFilter::setIntensity(int intensity) {
	if(intensity<-100||intensity>100)
		return;
	intensity_ = intensity;
}

void Model::SharpnessFilter::restore(QString description) {
	QStringList list  = description.split(";");
	if(list.size()!=1)
		return;
	setIntensity(list[0].QString::toInt());
}

QString Model::SharpnessFilter::getSaveString() const {
	QString str = QString::number(intensity_);
	return str;
}
