#include "FilterList.h"

#include <string>
#include <vector>
#include <algorithm>

#include <QString>

#include "filters/Filter.h"

Model::FilterList::FilterList() {

}

void Model::FilterList::swapFilter(std::size_t oldPosition, std::size_t newPosition) {
    if(oldPosition>=filters_.size()||newPosition>=filters_.size())
        return;
    iter_swap(filters_.begin() + oldPosition, filters_.begin() + newPosition);
}

void Model::FilterList::removeFilter(std::size_t position) {
    if(position>=filters_.size())
        return;
    filters_.erase(filters_.begin()+ position);
}

void Model::FilterList::addFilter(QString name) {
    filters_.push_back(std::move(Filter::createFilter(name)));
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
