#include "ScaleFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::ScaleFilter::FILTERNAME="Scale";

Model::ScaleFilter::ScaleFilter():width_(100), height_(200),keepRatio_(false),ratio_(2) {
}

std::string Model::ScaleFilter::getFilterDescription() {
    std::string str = std::string("scale=");
    if(keepRatio_){
        str+=std::to_string(ratio_);
        str+="*iw:";
        str+=std::to_string(ratio_);
        str+="*ih";
    } else {
        str+=std::to_string(width_);
        str+=":";
        str+=std::to_string(height_);
    }
	return str;
}

bool Model::ScaleFilter::getKeepRatio() {
	return keepRatio_;
}

void Model::ScaleFilter::setKeepRatio(bool keepRatio) {
	keepRatio_ = keepRatio;
}

QString Model::ScaleFilter::getName() {
	return FILTERNAME;
}

int Model::ScaleFilter::getWidth() {
	return width_;
}

void Model::ScaleFilter::setWidth(int width) {
	width_ = width;
}

int Model::ScaleFilter::getHeight() {
	return height_;
}

void Model::ScaleFilter::setHeight(int height) {
	height_ = height;
}

int Model::ScaleFilter::getRatio() {
	return ratio_;
}

void Model::ScaleFilter::setRatio(int ratio) {
	ratio_ = ratio;
}

void Model::ScaleFilter::restoreFilter(QString description) {
	QStringList list  = description.split(";");
	setWidth(list[0].QString::toInt());
	setHeight(list[1].QString::toInt());
	setKeepRatio(list[2].QString::toInt());
	setRatio(list[3].QString::toInt());
}

QString Model::ScaleFilter::getSaveString() {
	QString str = QString::number(width_);
	str+=";";
	str+=QString::number(height_);
	str+=";";
	str+=QString::number(keepRatio_);
	str+=";";
	str+=QString::number(ratio_);
	return str;
}
