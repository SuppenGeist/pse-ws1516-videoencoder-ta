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
	throw "Not yet implemented";
}

void Model::SepiaFilter::restoreFilter(string description){
    throw "Not yet implemented";
}
