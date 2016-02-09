#include "NoiseFilter.h"

#include <QString>
#include <QStringList>

#include "../NoiseMode.h"
#include "Filter.h"

const QString Model::NoiseFilter::FILTERNAME="Noise";

Model::NoiseFilter::NoiseFilter():mode_(NoiseMode::RANDOM),intensity_(50) {
}

std::string Model::NoiseFilter::getFilterDescription() {
    std::string str = std::string("noise=alls='" + std::to_string(intensity_) +"':allf=");
    if(mode_ == NoiseMode::STATIC){
    str+="a";
    } else if(mode_ == NoiseMode::RANDOM){
    str+="t+p";
    } else if(mode_ == NoiseMode::MUSTER){
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

QString Model::NoiseFilter::getName() {
	return FILTERNAME;
}

void Model::NoiseFilter::setIntensity(int intensity) {
    intensity_ = intensity;
}

void Model::NoiseFilter::restore(QString description) {
    QStringList list  = description.split(";");
    if(list.size()!=1)
        return;
    setIntensity(list[0].QString::toInt());
}

QString Model::NoiseFilter::getSaveString() {
        QString str = QString(mode_);
        return str;
}
