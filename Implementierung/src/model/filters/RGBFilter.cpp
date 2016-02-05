#include <exception>
#include <string>

#include "RGBFilter.h"
#include "../../utility/BasicColor.h"
#include "Filter.h"

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
	return "RGB";
}

void Model::RGBFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::RGBFilter::getSaveString() {

}
