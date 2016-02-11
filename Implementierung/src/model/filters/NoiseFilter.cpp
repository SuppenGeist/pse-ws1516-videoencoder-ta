#include "NoiseFilter.h"

#include <stdexcept>

#include <QString>
#include <QStringList>

#include "../NoiseMode.h"
#include "Filter.h"

const QString Model::NoiseFilter::FILTERNAME="Noise";

Model::NoiseFilter::NoiseFilter():mode_(NoiseMode::RANDOM),intensity_(50) {
}

std::string Model::NoiseFilter::getFilterDescription() {
	std::string str = std::string("noise=alls='" + std::to_string(intensity_) +"':allf=");
	if(mode_ == NoiseMode::STATIC) {
		str+="a";
	} else if(mode_ == NoiseMode::RANDOM) {
		str+="t+p";
	} else if(mode_ == NoiseMode::MUSTER) {
		str+="u";
	}
	return str;
}

Model::NoiseMode Model::NoiseFilter::getMode() {
	return mode_;
}

void Model::NoiseFilter::setMode(NoiseMode mode) {
	mode_ = mode;
}

int Model::NoiseFilter::getIntensity() {
	return intensity_;
}

QString Model::NoiseFilter::getName() const {
	return FILTERNAME;
}

void Model::NoiseFilter::setIntensity(int intensity) {
    if(intensity<0||intensity>100)
		return;
	intensity_ = intensity;
}

void Model::NoiseFilter::restore(QString description) {
	QStringList list  = description.split(";");
    if(list.size()!=2)
		return;
	setIntensity(list[0].QString::toInt());
    if(list[1]=="muster") {
        mode_=NoiseMode::MUSTER;
    }else if(list[1]=="random") {
        mode_=NoiseMode::RANDOM;
    }else if(list[1]=="static") {
        mode_=NoiseMode::STATIC;
    }
}

QString Model::NoiseFilter::getSaveString() const {
    QString str = QString::number(intensity_);
    str+=";";
    if(mode_==NoiseMode::MUSTER) {
        str+="muster";
    }else if(mode_==NoiseMode::RANDOM) {
        str+="random";
    }else if(mode_==NoiseMode::STATIC) {
        str+="static";
    }else {
        throw std::logic_error("should not get here");
    }
	return str;
}
