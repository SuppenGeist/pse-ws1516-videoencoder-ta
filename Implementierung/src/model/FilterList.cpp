#include "FilterList.h"

#include <stdexcept>

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include <QString>
#include <QDebug>

#include "filters/Filter.h"

Model::FilterList::FilterList() {
}

Model::FilterList::FilterList(Model::FilterList &obj) {
	for(std::size_t i=0; i<obj.getSize(); i++) {
		auto filter=obj.getFilter(i);
		appendFilter(filter->getName())->restore(filter->getSaveString());
	}
}

void Model::FilterList::moveFilter(std::size_t oldPosition, std::size_t newPosition) {
	if(oldPosition>=filters_.size()||newPosition>filters_.size()-1||oldPosition==newPosition)
		return;
	auto filter=removeFilter(oldPosition);
	insertFilter(std::move(filter),newPosition);
}

std::unique_ptr<Model::Filter> Model::FilterList::removeFilter(std::size_t position) {
	if(position>=filters_.size()) {
		throw std::logic_error("Check your index!");
	}

	auto filter=std::move(filters_[position]);
	filters_.erase(filters_.begin()+ position);

	return std::move(filter);
}

void Model::FilterList::insertFilter(std::unique_ptr<Model::Filter> filter, std::size_t index) {
	if(index>filters_.size())
		return;
	filters_.insert(filters_.begin()+index,std::move(filter));
}

Model::Filter* Model::FilterList::appendFilter(QString name) {
	filters_.push_back(std::move(Filter::CreateFilter(name)));
	return filters_.back().get();
}

Model::Filter* Model::FilterList::getFilter(std::size_t index) {
	if(index>=filters_.size())
		return nullptr;
	return filters_[index].get();
}

std::size_t Model::FilterList::getSize() {
	return filters_.size();
}
