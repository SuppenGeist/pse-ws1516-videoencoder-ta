#include "FilterTabMemento.h"

#include <memory>
#include <stdexcept>

#include "../model/YuvVideo.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

Memento::FilterTabMemento::FilterTabMemento():rawVideo_(nullptr),isPreviewShow_(false) {

}

void Memento::FilterTabMemento::setRawVideo(Model::YuvVideo *rawVideo) {
	rawVideo_=rawVideo;
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
	isPreviewShow_=isShown;
}

bool Memento::FilterTabMemento::isPreviewShow() {
    return isPreviewShow_;
}

void Memento::FilterTabMemento::setIsFilteredVideoShown(bool isShown)
{
    isFilteredVideoShown_=isShown;
}

bool Memento::FilterTabMemento::isFilteredVideoShown()
{
    return isFilteredVideoShown_;
}

void Memento::FilterTabMemento::setFilteredVideo(Model::Video *filteredVideo)
{
    filteredVideo_=filteredVideo;
}

Model::Video *Memento::FilterTabMemento::getFilteredVideo()
{
    return filteredVideo_;
}

