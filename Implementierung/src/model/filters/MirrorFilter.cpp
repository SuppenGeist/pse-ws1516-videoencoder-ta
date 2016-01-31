#include <exception>
#include <string>

#include "MirrorFilter.h"
#include "../MirrorMode.h"
#include "Filter.h"

Model::MirrorFilter::MirrorFilter() {
}

std::string Model::MirrorFilter::getFilterDescription() {
	throw "Not yet implemented";
}

<<<<<<< HEAD
std::string Model::MirrorFilter::getName() {
    return "Mirror";
=======
string Model::MirrorFilter::getName() {
	return "Mirror";
>>>>>>> origin/master
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
