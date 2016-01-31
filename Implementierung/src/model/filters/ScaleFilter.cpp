#include <exception>
#include <QString>
#include <QStringList>
#include "ScaleFilter.h"
#include "Filter.h"

Model::ScaleFilter::ScaleFilter() {
}

<<<<<<< HEAD
std::string Model::ScaleFilter::getFilterDescription() {
    std::string str = std::string(getName());
    str+="=";
    str+=std::to_string(getWidth());
    str+=":";
    str+=std::to_string(getHeight());
    return str;
=======
string Model::ScaleFilter::getFilterDescription() {
	std::string str = std::string(getName());
	str+="=";
	str+=to_string(getWidth());
	str+=":";
	str+=to_string(getHeight());
	return str;
>>>>>>> origin/master
}

bool Model::ScaleFilter::getKeepRatio() {
	return this->keepRatio;
}

void Model::ScaleFilter::setKeepRatio(bool keepRatio) {
	this->keepRatio = keepRatio;
}

<<<<<<< HEAD
std::string Model::ScaleFilter::getName() {
    return "Scale";
=======
string Model::ScaleFilter::getName() {
	return "Scale";
>>>>>>> origin/master
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
	str+=QString::number(getWidth());
	str+=";";
	str+=QString::number(getHeight());
	str+=";";
	str+=QString::number(getKeepRatio());
	str+=";";
	str+=QString::number(getRatio());
	return str;
}
