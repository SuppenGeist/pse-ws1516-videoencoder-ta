#include "LoadFilterconfig.h"

#include <memory>

#include "../gui/FilterTab.h"
#include "../model/FilterList.h"

UndoRedo::LoadFilterconfig::LoadFilterconfig(GUI::FilterTab& filterTab, std::unique_ptr<Model::FilterList> list):filterTab_(&filterTab),newList_(std::move(list)) {

}

void UndoRedo::LoadFilterconfig::undo() {
    newList_=filterTab_->releaseFilterList();
    filterTab_->setFilterList(std::move(oldList_));
}

void UndoRedo::LoadFilterconfig::redo() {
    oldList_=filterTab_->releaseFilterList();
    filterTab_->setFilterList(std::move(newList_));
}
