#include <exception>
#include <string>

#include "VintageFilter.h"
#include "Filter.h"

Model::VintageFilter::VintageFilter() {
}

string Model::VintageFilter::getName() {
    return "Vintage";
}

string Model::VintageFilter::getFilterDescription() {
	throw "Not yet implemented";
}


