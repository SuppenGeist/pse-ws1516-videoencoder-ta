#include "FilterApplier.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include <memory>

#include "../model/FilterList.h"
#include "../model/AVVideo.h"

class AVFrame;

Utility::FilterApplier::FilterApplier(Model::FilterList& list):list_(&list) {
    initFilters();
}



void Utility::FilterApplier::applyToVideo(Model::AVVideo& target, Model::AVVideo& video) {
    for(std::size_t i=0;i<video.getNumberOfFrames();i++) {
        target.appendFrame(std::move(applyToFrame(*video.getFrame(i))));
    }
}

void Utility::FilterApplier::initFilters() {

}

std::unique_ptr<AVFrame> Utility::FilterApplier::applyToFrame(AVFrame& frame) {

}
