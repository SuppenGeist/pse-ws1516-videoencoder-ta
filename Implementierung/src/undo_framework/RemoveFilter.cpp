#include "RemoveFilter.h"

#include "../gui/FilterTab.h"
#include "../model/filters/Filter.h"

UndoRedo::RemoveFilter::RemoveFilter(GUI::FilterTab& filterTab, int index):filterTab_(&filterTab),
	index_(index) {
    memento_=filterTab.getMemento();
}

void UndoRedo::RemoveFilter::undo() {
    filterTab_->restore(memento_.get());
}

void UndoRedo::RemoveFilter::redo() {
    filter_=filterTab_->removeFilter(index_);
}
