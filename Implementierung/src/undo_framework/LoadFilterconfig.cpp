#include "LoadFilterconfig.h"

#include <memory>

#include "../gui/FilterTab.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

UndoRedo::LoadFilterconfig::LoadFilterconfig(GUI::FilterTab& filterTab,
        std::unique_ptr<Model::FilterList> oldList, std::unique_ptr<Model::FilterList> newList):filterTab_(&filterTab),oldList_(std::move(oldList)),newList_(std::move(newList)) {

}

void UndoRedo::LoadFilterconfig::undo() {
    filterTab_->setFilterList(std::make_unique<Model::FilterList>(*oldList_));
}

void UndoRedo::LoadFilterconfig::redo() {
    filterTab_->setFilterList(std::make_unique<Model::FilterList>(*newList_));
}
