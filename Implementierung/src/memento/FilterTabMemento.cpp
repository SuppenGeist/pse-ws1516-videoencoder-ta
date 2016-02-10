#include "FilterTabMemento.h"

#include <string>

#include "../model/FilterList.h"

Memento::FilterTabMemento::FilterTabMemento() {
}

Model::FilterList* Memento::FilterTabMemento::getFilterList() {
    return this->filterList_;
}

void Memento::FilterTabMemento::setFilterList(Model::FilterList *filterList) {
    this->filterList_ = filterList;
}

bool Memento::FilterTabMemento::getWasApplied() {
    return this->wasApplied_;
}

void Memento::FilterTabMemento::setWasApplied(bool wasApplied) {
    this->wasApplied_ = wasApplied;
}

int Memento::FilterTabMemento::getDisplayedFrame() {
    return this->displayedFrame_;
}

void Memento::FilterTabMemento::setDisplayedFrame(int displayedFrame) {
    this->displayedFrame_ = displayedFrame;
}

std::string Memento::FilterTabMemento::getLoadedFile() {
    return yuvPath_;
}

void Memento::FilterTabMemento::setLoadedFile(std::string loadedFile) {
    yuvPath_ = loadedFile;
}

int Memento::FilterTabMemento::getFps() {
 return yuvFps_;
}


int Memento::FilterTabMemento::getWidth() {
    return yuvWidth_;
}


int Memento::FilterTabMemento::getHeight() {
    return yuvHeight_;
}

Utility::Compression Memento::FilterTabMemento::getCompression() {
    return yuvCompession_;
}

Utility::YuvType Memento::FilterTabMemento::getPixelSheme() {
    return yuvPixelScheme_;
}

void Memento::FilterTabMemento::setFps(int fps) {
    yuvFps_ = fps;
}

void Memento::FilterTabMemento::setWidth(int width) {
    yuvWidth_ = width;
}

void Memento::FilterTabMemento::setHeight(int height) {
    yuvHeight_ = height;
}

void Memento::FilterTabMemento::setCompression(Utility::Compression comp) {
    yuvCompession_ = comp;
}

void Memento::FilterTabMemento::setPixelSheme(Utility::YuvType sheme) {
    yuvPixelScheme_ = sheme;
}
