#include "FilterList.h"

#include <string>
#include <vector>
#include <algorithm>

#include <QString>

#include "filters/Filter.h"

Model::FilterList::FilterList() {

}

void Model::FilterList::moveFilter(std::size_t oldPosition, std::size_t newPosition) {
    if(oldPosition>=filters_.size()||newPosition>filters_.size()||oldPosition==newPosition)
        return;
    auto filter=removeFilter(oldPosition);
    insertFilter(std::move(filter),newPosition);
}

std::unique_ptr<Model::Filter> Model::FilterList::removeFilter(std::size_t position) {
    std::unique_ptr<Model::Filter> f;
    if(position>=filters_.size()) {
        f.release();
        return std::move(f);
    }
    auto filter=std::move(filters_[position]);
    filters_.erase(filters_.begin()+ position);

    return std::move(filter);
}

void Model::FilterList::insertFilter(std::unique_ptr<Model::Filter> filter, std::size_t index)
{
    if(index>filters_.size())
        return;
    filters_.insert(filters_.begin()+index,std::move(filter));
}

void Model::FilterList::appendFilter(QString name) {
    filters_.push_back(std::move(Filter::CreateFilter(name)));
}

Model::Filter* Model::FilterList::getFilter(std::size_t index) {
    if(index>=filters_.size())
        return nullptr;
    return filters_[index].get();
}

std::size_t Model::FilterList::getSize()
{
    return filters_.size();
}
