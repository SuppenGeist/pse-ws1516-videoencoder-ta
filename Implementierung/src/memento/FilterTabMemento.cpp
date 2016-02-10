#include "FilterTabMemento.h"

#include <memory>

#include "../model/YuvVideo.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

Memento::FilterTabMemento::FilterTabMemento():rawVideo_(nullptr),isPreviewShow_(false) {

}

void Memento::FilterTabMemento::setRawVideo(Model::YuvVideo *rawVideo)
{
    rawVideo_=rawVideo;
}

Model::YuvVideo *Memento::FilterTabMemento::getRawVideo()
{
    return rawVideo_;
}

void Memento::FilterTabMemento::setFilterList( Model::FilterList &filterlist)
{
    filterlist_=std::make_unique<Model::FilterList>(filterlist);
}

std::unique_ptr<Model::FilterList> Memento::FilterTabMemento::getFilterList()
{
    if(!filterlist_.get())
        return std::unique_ptr<Model::FilterList>();
    return std::make_unique<Model::FilterList>(*filterlist_);
}

void Memento::FilterTabMemento::setIsPreviewShown(bool isShown)
{
    isPreviewShow_=isShown;
}

bool Memento::FilterTabMemento::isPreviewShow()
{
    return isPreviewShow_;
}

