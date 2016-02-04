#include <exception>
#include <QString>
#include <QStringList>
#include "BlurFilter.h"
#include "Filter.h"

Model::BlurFilter::BlurFilter() {
}

bool Model::BlurFilter::getPreserveEdges() {
	return this->preserveEdges;
}

void Model::BlurFilter::setPreserveEdges(bool preserveEdges) {
	this->preserveEdges = preserveEdges;
}

int Model::BlurFilter::getIntensity() {
	return this->intensity;
}

void Model::BlurFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

std::string Model::BlurFilter::getFilterDescription() {
	std::string str = std::string("");
	if(preserveEdges) {
		str += "smartblur";
	} else {
		str += "boxblur";
	}
	str += "=";
	str+=std::to_string(intensity);
	return str;
}

std::string Model::BlurFilter::getName() {
	return "Blur";
}

void Model::BlurFilter::restoreFilter(QString description) {
	QStringList list  = description.split(";");
	setPreserveEdges(list[1].QString::toInt());
	setIntensity(list[2].QString::toInt());
}

QString Model::BlurFilter::getSaveString() {
	QString str = QString::fromStdString(getName());
	str+=";";
	str+=QString::number(preserveEdges);
	str+=";";
	str+=QString::number(intensity);
	return str;
}
