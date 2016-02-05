#include "NoiseFilter.h"

#include <QString>
#include <QStringList>

#include "../NoiseMode.h"
#include "Filter.h"

const QString Model::NoiseFilter::FILTERNAME="Noise";

Model::NoiseFilter::NoiseFilter() {
}

std::string Model::NoiseFilter::getFilterDescription() {
	throw "Not yet implemented";
}

Model::NoiseMode Model::NoiseFilter::getMode() {
	throw "Not yet implemented";
}

void Model::NoiseFilter::setMode(NoiseMode mode) {
	throw "Not yet implemented";
}

int Model::NoiseFilter::getIntensity() {
	return this->intensity;
}

QString Model::NoiseFilter::getName() {
    return FILTERNAME;
}

void Model::NoiseFilter::setIntensity(int intensity) {
	this->intensity = intensity;
}

void Model::NoiseFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::NoiseFilter::getSaveString() {
}
