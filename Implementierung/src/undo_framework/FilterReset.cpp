#include "FilterReset.h"

#include <memory>

#include "../gui/FilterTab.h"
#include "../model/FilterList.h"

UndoRedo::FilterReset::FilterReset(GUI::FilterTab& filterTab, std::unique_ptr<Model::FilterList> filterList):filterTab_(&filterTab),filterList_(std::move(filterList)) {
}

void UndoRedo::FilterReset::undo() {
    filterTab_->setFilterList(std::make_unique<Model::FilterList>(*filterList_));
    if(filterList_->getSize()>0)
        filterTab_->showFilterPreview();
}

void UndoRedo::FilterReset::redo() {
    filterTab_->resetFilters();
}
