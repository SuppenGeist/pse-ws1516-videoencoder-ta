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
	anaBox_ = container_->appendVideo(filename_);
}

void UndoRedo::RemoveVideo::redo() {
	container_->removeVideo(anaBox_);
}
