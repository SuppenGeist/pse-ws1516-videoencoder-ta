#include <exception>
#include <QString>
#include <QStringList>
#include "ScaleFilter.h"
#include "Filter.h"

Model::ScaleFilter::ScaleFilter() {
}

std::string Model::ScaleFilter::getFilterDescription() {
	std::string str = std::string("scale");
	str+="=";
	str+=std::to_string(width);
	str+=":";
	str+=std::to_string(height);
	return str;
}

bool Model::ScaleFilter::getKeepRatio() {
	return this->keepRatio;
}

void Model::ScaleFilter::setKeepRatio(bool keepRatio) {
	this->keepRatio = keepRatio;
}

std::string Model::ScaleFilter::getName() {
	return "Scale";
}

int Model::ScaleFilter::getWidth() {
	return this->width;
}

void Model::ScaleFilter::setWidth(int width) {
	this->width = width;
}

int Model::ScaleFilter::getHeight() {
	return this->height;
}

void Model::ScaleFilter::setHeight(int height) {
	this->height = height;
}

int Model::ScaleFilter::getRatio() {
	return this->ratio;
}

void Model::ScaleFilter::setRatio(int ratio) {
	this->ratio = ratio;
}

void Model::ScaleFilter::restoreFilter(QString description) {
	QStringList list  = description.split(";");
	setWidth(list[1].QString::toInt());
	setHeight(list[2].QString::toInt());
	setKeepRatio(list[3].QString::toInt());
	setRatio(list[4].QString::toInt());
}

QString Model::ScaleFilter::getSaveString() {
	QString str = QString::fromStdString(getName());
	str+=";";
	str+=QString::number(width);
	str+=";";
	str+=QString::number(height);
	str+=";";
	str+=QString::number(keepRatio);
	str+=";";
	str+=QString::number(ratio);
	return str;
}
