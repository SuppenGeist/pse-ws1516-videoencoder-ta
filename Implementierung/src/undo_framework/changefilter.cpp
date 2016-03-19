#include "changefilter.h"

#include <QString>


UndoRedo::ChangeFilter::ChangeFilter(GUI::FilterTab& filtertab, int index, QString oldState,
                                     QString newState):newState_(newState),oldState_(oldState),index_(index),filtertab_(&filtertab) {
	memento_=filtertab.getMemento();
}

void UndoRedo::ChangeFilter::undo() {
    filtertab_->changeFilter(index_,oldState_);
}

void UndoRedo::ChangeFilter::redo() {
	filtertab_->changeFilter(index_,newState_);
}
