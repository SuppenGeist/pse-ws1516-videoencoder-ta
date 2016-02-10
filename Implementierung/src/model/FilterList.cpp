#include "FilterList.h"

#include <string>
#include <vector>
#include <algorithm>

#include <QString>
#include <QDebug>

#include "filters/Filter.h"

Model::FilterList::FilterList() {
}

Model::FilterList::FilterList(Model::FilterList &obj) {
	for(std::size_t i=0; i<obj.getSize(); i++) {
		appendFilter(obj.getFilter(i)->getName())->restore(obj.getFilter(i)->getSaveString());
	}
}

void Model::FilterList::moveFilter(std::size_t oldPosition, std::size_t newPosition) {
	if(oldPosition>=filters_.size()||newPosition>filters_.size()||oldPosition==newPosition)
		return;
	auto filter=removeFilter(oldPosition);
	insertFilter(std::move(filter),newPosition);
}

std::unique_ptr<Model::Filter> Model::FilterList::removeFilter(std::size_t position) {
	if(position>=filters_.size()) {
		return std::unique_ptr<Model::Filter>();
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
