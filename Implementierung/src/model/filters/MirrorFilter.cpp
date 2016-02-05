#include "MirrorFilter.h"

#include <QString>
#include <QStringList>

#include "../MirrorMode.h"
#include "Filter.h"

const QString Model::MirrorFilter::FILTERNAME="Mirror";

Model::MirrorFilter::MirrorFilter() {
}

std::string Model::MirrorFilter::getFilterDescription() {
	throw "Not yet implemented";
}

QString Model::MirrorFilter::getName() {
    return FILTERNAME;
}

Model::MirrorMode Model::MirrorFilter::getMode() {
	throw "Not yet implemented";
}

void Model::MirrorFilter::setMode(MirrorMode mode) {
	throw "Not yet implemented";
}

void Model::MirrorFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::MirrorFilter::getSaveString() {

}
