#include "MirrorFilter.h"

#include <QString>
#include <QStringList>

#include <string>
#include <stdexcept>

#include "../MirrorMode.h"
#include "Filter.h"

const QString Model::MirrorFilter::FILTERNAME="Mirror";

Model::MirrorFilter::MirrorFilter():mode_(MirrorMode::HORIZONTAL) {

}

std::string Model::MirrorFilter::getFilterDescription() {
	if(mode_==MirrorMode::HORIZONTAL) {
        return "hflip";
	} else  if(mode_==MirrorMode::VERTICAL) {
        return "vflip";
	}
	throw std::logic_error("Should not get here");
}

QString Model::MirrorFilter::getName() {
	return FILTERNAME;
}

Model::MirrorMode Model::MirrorFilter::getMode() {
	return mode_;
}

void Model::MirrorFilter::setMode(MirrorMode mode) {
	mode_=mode;
}

void Model::MirrorFilter::restoreFilter(QString description) {

}

QString Model::MirrorFilter::getSaveString() {

}
