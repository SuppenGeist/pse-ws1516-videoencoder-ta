#include "AddFilter.h"

#include <QString>

#include <memory>

#include "UndoStack.h"
#include "../gui/FilterTab.h"

UndoRedo::AddFilter::AddFilter(GUI::FilterTab &filterTab,
                               QString filtername):filterTab_(&filterTab),filtername_(filtername) {
	memento_=filterTab.getMemento();
}

void UndoRedo::AddFilter::undo() {
	filterTab_->restore(memento_.get());
}

void UndoRedo::AddFilter::redo() {
	filterTab_->appendFilter(filtername_);
	filterTab_->showFilterPreview();
}
