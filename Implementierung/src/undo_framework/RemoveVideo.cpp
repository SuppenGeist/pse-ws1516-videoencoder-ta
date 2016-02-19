#include "RemoveVideo.h"

#include <QUndoCommand>

#include "../gui/AnalysisBox.h"
#include "../gui/AnalysisBoxContainer.h"
#include "../memento/AnalysisBoxMemento.h"

UndoRedo::RemoveVideo::RemoveVideo(GUI::AnalysisBoxContainer *boxContainer,
                                   GUI::AnalysisBox* box):anaBox_(box),container_(boxContainer) {
    boxMemento_=std::move(anaBox_->getMemento());
}

void UndoRedo::RemoveVideo::undo() {
    anaBox_ = container_->insertNewBox(index_, &*boxMemento_);
}

void UndoRedo::RemoveVideo::redo() {
    index_=container_->removeVideo(anaBox_);
}
