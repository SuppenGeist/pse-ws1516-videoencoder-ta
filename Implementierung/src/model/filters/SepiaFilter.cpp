#include <exception>
#include <string>

#include "SepiaFilter.h"
#include "Filter.h"

Model::SepiaFilter::SepiaFilter() {
}

string Model::SepiaFilter::getName() {
	return "Sepia";
}

string Model::SepiaFilter::getFilterDescription() {
	string str = "colorchannelmixer=.393:.769:.189:0:.349:.686:.168:0:.272:.534:.131";
	return str;
}

void Model::SepiaFilter::restoreFilter(QString description) {
//nothing to save
}

QString Model::SepiaFilter::getSaveString() {
//nothing to save
}
