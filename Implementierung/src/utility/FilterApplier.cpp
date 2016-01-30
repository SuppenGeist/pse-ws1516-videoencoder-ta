#include "FilterApplier.h"

#include "../model/FilterList.h"
#include "../model/AVVideo.h"

class AVFrame;

Utility::FilterApplier::FilterApplier(Model::FilterList& list) {
}

void Utility::FilterApplier::applyToVideo(Model::AVVideo& target, Model::AVVideo& video) {
	throw "Not yet implemented";
}

void Utility::FilterApplier::initFilters() {
	throw "Not yet implemented";
}

AVFrame Utility::FilterApplier::applyToFrame(AVFrame& frame) {
	throw "Not yet implemented";
}
