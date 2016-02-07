#include "RGBFilter.h"

#include <QString>
#include <QStringList>

#include "../../utility/BasicColor.h"
#include "Filter.h"

const QString Model::RGBFilter::FILTERNAME="RGB";

Model::RGBFilter::RGBFilter() {
}

std::string Model::RGBFilter::getFilterDescription() {
	throw "Not yet implemented";
}

Model::BasicColor Model::RGBFilter::getColor() {
	throw "Not yet implemented";
}

void Model::RGBFilter::setColor(BasicColor color) {
	throw "Not yet implemented";
}

QString Model::RGBFilter::getName() {
	return FILTERNAME;
}

void Model::RGBFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::RGBFilter::getSaveString() {

}
