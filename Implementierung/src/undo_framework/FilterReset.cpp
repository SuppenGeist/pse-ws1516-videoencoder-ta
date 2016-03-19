#include "FilterReset.h"

#include <memory>

#include "../gui/FilterTab.h"
#include "../model/FilterList.h"

UndoRedo::FilterReset::FilterReset(GUI::FilterTab& filterTab):filterTab_(&filterTab) {
}

void UndoRedo::FilterReset::undo() {
    std::size_t size = filterList_->getSize();
    for(std::size_t i = 0; i < size - 1; i++) {
        filterTab_->insertFilter(filterList_->removeFilter(0),i,false);
    }
    filterTab_->insertFilter(filterList_->removeFilter(0),size-1,true);
}

void UndoRedo::FilterReset::redo() {
    filterList_ = new Model::FilterList(*filterTab_->getFilterList());
    for(std::size_t i = 0; i < filterList_->getSize(); i++) {
        filterTab_->removeFilter(filterList_->getSize()-i-1);
    }
}
