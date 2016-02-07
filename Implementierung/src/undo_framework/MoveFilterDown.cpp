#include "MoveFilterDown.h"

#include "../gui/FilterTab.h"

UndoRedo::MoveFilterDown::MoveFilterDown(GUI::FilterTab& filterTab, int index):index_(index),
	filterTab_(&filterTab) {
}

void UndoRedo::MoveFilterDown::undo() {
	filterTab_->moveFilter(index_,index_+1);
}

void UndoRedo::MoveFilterDown::redo() {
	filterTab_->moveFilter(index_,index_+1);
}
