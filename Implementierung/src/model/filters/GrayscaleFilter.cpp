#include "GrayscaleFilter.h"

#include <QString>

#include <string>

#include "Filter.h"

const QString Model::GrayscaleFilter::FILTERNAME="Grayscale";

Model::GrayscaleFilter::GrayscaleFilter() {

}

QString Model::GrayscaleFilter::getName() const {
	return FILTERNAME;
}

std::string Model::GrayscaleFilter::getFilterDescription() {
	return "colorchannelmixer=',3':',4':',3':0:',3':',4':',3':0:',3':',4':',3'";
}
void Model::GrayscaleFilter::restore(QString) {
	//nothing to load
}

QString Model::GrayscaleFilter::getSaveString() const {
	return "";
}
