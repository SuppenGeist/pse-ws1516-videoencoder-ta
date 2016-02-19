#include "RemoveVideo.h"

#include <QUndoCommand>

#include "../gui/AnalysisBox.h"
#include "../gui/AnalysisBoxContainer.h"
#include "../memento/AnalysisBoxMemento.h"

UndoRedo::RemoveVideo::RemoveVideo(GUI::AnalysisBoxContainer *boxContainer,
                                   GUI::AnalysisBox* box):anaBox_(box),container_(boxContainer) {
	boxMemento_=anaBox_->getMemento();
}

void UndoRedo::RemoveVideo::undo() {
	anaBox_ = container_->insertBox(new GUI::AnalysisBox,index_);
	anaBox_->restore(boxMemento_.get());
}

void UndoRedo::RemoveVideo::redo() {
	index_=container_->removeBox(anaBox_);
}
