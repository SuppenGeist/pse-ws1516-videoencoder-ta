#include <exception>
#include <string>

#include "MirrorFilter.h"
#include "../MirrorMode.h"
#include "Filter.h"

Model::MirrorFilter::MirrorFilter() {
}

string Model::MirrorFilter::getFilterDescription() {
	throw "Not yet implemented";
}

string Model::MirrorFilter::getName() {
    return "Mirror";
}

Model::MirrorMode Model::MirrorFilter::getMode() {
	throw "Not yet implemented";
}

void Model::MirrorFilter::setMode(MirrorMode mode) {
	throw "Not yet implemented";
}

void Model::MirrorFilter::restoreFilter(string description){
    throw "Not yet implemented";
}
