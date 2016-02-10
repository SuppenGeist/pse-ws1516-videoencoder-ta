#include "AddFilter.h"

#include <QString>

#include <memory>

#include "UndoStack.h"
#include "../gui/FilterTab.h"

UndoRedo::AddFilter::AddFilter(GUI::FilterTab &filterTab,
                               QString filtername):filterTab_(&filterTab),filtername_(filtername) {

}

void UndoRedo::AddFilter::undo() {
    //filterTab_->removeFilter(filterTab_->getFilterList()->getSize()-1);
}

void UndoRedo::AddFilter::redo() {
    //filterTab_->addFilter(filtername_);
}
