#include "FilterReset.h"

#include <memory>

#include "../gui/FilterTab.h"
#include "../model/FilterList.h"

UndoRedo::FilterReset::FilterReset(GUI::FilterTab& filterTab):filterTab_(&filterTab){
    memento_=filterTab.getMemento();
}

void UndoRedo::FilterReset::undo() {
    filterTab_->restore(memento_.get());
}

void UndoRedo::FilterReset::redo() {
	filterTab_->resetFilters();
}
