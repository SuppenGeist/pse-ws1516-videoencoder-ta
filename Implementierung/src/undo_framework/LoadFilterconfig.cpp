#include "LoadFilterconfig.h"

#include <memory>

#include "../gui/FilterTab.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

UndoRedo::LoadFilterconfig::LoadFilterconfig(GUI::FilterTab& filterTab,
        std::unique_ptr<Model::FilterList> newList):filterTab_(&filterTab),newList_(std::move(newList)) {
	memento_=filterTab.getMemento();
}

void UndoRedo::LoadFilterconfig::undo() {
	filterTab_->restore(memento_.get());
}

void UndoRedo::LoadFilterconfig::redo() {
	filterTab_->setFilterList(std::make_unique<Model::FilterList>(*newList_));
}
