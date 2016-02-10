#include "RemoveFilter.h"

#include "../gui/FilterTab.h"
#include "../model/filters/Filter.h"

UndoRedo::RemoveFilter::RemoveFilter(GUI::FilterTab& filterTab, int index):filterTab_(&filterTab),
	index_(index) {
}

void UndoRedo::RemoveFilter::undo() {
	//filterTab_->insertFilter(std::move(filter_),index_);
}

void UndoRedo::RemoveFilter::redo() {
	//filter_=filterTab_->removeFilter(index_);
}
