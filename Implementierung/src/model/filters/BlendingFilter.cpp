#include "BlendingFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::BlendingFilter::FILTERNAME="Blending";

Model::BlendingFilter::BlendingFilter() {
}

bool Model::BlendingFilter::getInBlend() {
	return this->inBlend;
}

void Model::BlendingFilter::setInBlend(bool inBlend) {
	this->inBlend = inBlend;
}

int Model::BlendingFilter::getStartFrame() {
	return this->startFrame;
}

void Model::BlendingFilter::setStartFrame(int startFrame) {
	this->startFrame = startFrame;
}

int Model::BlendingFilter::getEndFrame() {
	return this->endFrame;
}

void Model::BlendingFilter::setEndFrame(int endFrame) {
	this->endFrame = endFrame;
}

QString Model::BlendingFilter::getName() {
    return FILTERNAME;
}

std::string Model::BlendingFilter::getFilterDescription() {
	throw "Not yet implemented";
}


void Model::BlendingFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::BlendingFilter::getSaveString() {

}
