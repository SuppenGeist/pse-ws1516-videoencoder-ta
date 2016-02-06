#include "MoveFilterUp.h"

#include "../gui/FilterTab.h"

UndoRedo::MoveFilterUp::MoveFilterUp(GUI::FilterTab& filterTab, int index):index_(index),filterTab_(&filterTab) {
}

void UndoRedo::MoveFilterUp::undo() {
    filterTab_->moveFilter(index_,index_-1);
}

void UndoRedo::MoveFilterUp::redo() {
    filterTab_->moveFilter(index_,index_-1);
}
