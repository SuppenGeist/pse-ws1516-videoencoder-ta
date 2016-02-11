#include "MirrorFilter.h"

#include <QString>
#include <QStringList>
#include <QDebug>

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

QString Model::MirrorFilter::getName() const {
	return FILTERNAME;
}

Model::MirrorMode Model::MirrorFilter::getMode() {
	return mode_;
}

void Model::MirrorFilter::setMode(MirrorMode mode) {
	mode_=mode;
}

void Model::MirrorFilter::restore(QString description) {
    QStringList list  = description.split(";");
    if(list.size()!=1)
        return;
    if(list[0]=="hor") {
        mode_=MirrorMode::HORIZONTAL;
    }
    else if(list[0]=="ver") {
        mode_=MirrorMode::VERTICAL;
    }

}

QString Model::MirrorFilter::getSaveString() const {
    if(mode_==MirrorMode::HORIZONTAL)
        return "hor";
    else if(mode_==MirrorMode::VERTICAL)
        return "ver";
    throw std::logic_error("Should not gte here");
}
