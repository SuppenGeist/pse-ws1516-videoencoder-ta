#include "RemoveVideo.h"

#include <QUndoCommand>

#include "../gui/AnalysisBox.h"
#include "../gui/AnalysisBoxContainer.h"
#include "../memento/AnalysisBoxMemento.h"

UndoRedo::RemoveVideo::RemoveVideo(GUI::AnalysisBoxContainer *boxConatiner,
                                   GUI::AnalysisBox* box):anaBox_(box),container_(boxConatiner) {
	filename_=anaBox_->getFilename();
}

void UndoRedo::RemoveVideo::undo() {
    anaBox_ = container_->insertVideo(filename_,index_);
}

void UndoRedo::RemoveVideo::redo() {
    index_=container_->removeVideo(anaBox_);
}
