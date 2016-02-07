#include "MirrorFilter.h"

#include <QString>
#include <QStringList>

#include <string>
#include <stdexcept>

#include "../MirrorMode.h"
#include "Filter.h"

const QString Model::MirrorFilter::FILTERNAME="Mirror";

Model::MirrorFilter::MirrorFilter():mode_(MirrorMode::VERTICAL) {

}

std::string Model::MirrorFilter::getFilterDescription() {
	if(mode_==MirrorMode::HORIZONTAL) {
        return "'pad=iw:2*ih[left]; [tmp]vflip [right];[left][right] overlay=0:main_h/2'" ;//return "crop=iw/2:ih:0:0,split[left][tmp];[tmp]hflip[right];[left][right] hstack";
	} else  if(mode_==MirrorMode::VERTICAL) {
        return "'pad=iw:2*ih [top]; [tmp]vflip [bottom];[top][bottom] overlay=0:main_h/2'";// return ""crop=iw/2:ih:0:0,split[top][tmp];[tmp]vflip[bottom];[top][bottom] vstack""
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
