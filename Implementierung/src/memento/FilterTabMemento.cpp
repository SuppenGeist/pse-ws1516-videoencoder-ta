#include "FilterTabMemento.h"

#include <memory>
#include <stdexcept>

#include "../model/YuvVideo.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

Memento::FilterTabMemento::FilterTabMemento():rawVideo_(nullptr),isPreviewShown_(false),
	currentFrame_(0),currentlySelectedFilter_(-1),isFilteredVideoShown_(false) {
	filterlist_=std::make_unique<Model::FilterList>();
}

void Memento::FilterTabMemento::setRawVideo(Model::YuvVideo *rawVideo) {
    rawVideo_=rawVideo;
}

void Memento::FilterTabMemento::setRawVideo(std::unique_ptr<Model::YuvVideo> video)
{
    ownedRawVideo_=std::move(video);
}

std::unique_ptr<Model::YuvVideo> Memento::FilterTabMemento::releaseVideo()
{
    return std::move(ownedRawVideo_);
}

Model::YuvVideo *Memento::FilterTabMemento::getRawVideo() {
	return rawVideo_;
}

void Memento::FilterTabMemento::setFilterList( std::unique_ptr<Model::FilterList> filterlist) {
	filterlist_=std::move(filterlist);
}

std::unique_ptr<Model::FilterList> Memento::FilterTabMemento::getFilterList() {
	if(!filterlist_.get())
		throw std::logic_error("First set the filterlist");
	return std::make_unique<Model::FilterList>(*filterlist_);
}

void Memento::FilterTabMemento::setIsPreviewShown(bool isShown) {
	isPreviewShown_=isShown;
}

bool Memento::FilterTabMemento::isPreviewShow() {
	return isPreviewShown_;
}

void Memento::FilterTabMemento::setIsFilteredVideoShown(bool isShown) {
	isFilteredVideoShown_=isShown;
}

bool Memento::FilterTabMemento::isFilteredVideoShown() {
	return isFilteredVideoShown_;
}

void Memento::FilterTabMemento::setCurrentFrame(int currentFrame) {
	currentFrame_=currentFrame;
}

int Memento::FilterTabMemento::getCurrentFrame() {
	return currentFrame_;
}

void Memento::FilterTabMemento::setCurrentlySelectedFilter(int filter) {
	currentlySelectedFilter_=filter;
}

int Memento::FilterTabMemento::getCurrentlySelectedFilter() {
	return currentlySelectedFilter_;
}

