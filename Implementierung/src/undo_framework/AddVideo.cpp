#include "AddVideo.h"

#include <QUndoCommand>
#include <QString>

#include "../gui/AnalysisBoxContainer.h"


UndoRedo::AddVideo::AddVideo(GUI::AnalysisBoxContainer* anaBoxContainer,
                             QString filename):anaBoxContainer_(anaBoxContainer),filename_(filename) {
}

void UndoRedo::AddVideo::undo() {
	anaBoxContainer_->removeVideo(box_);
}

void UndoRedo::AddVideo::redo() {
	box_=anaBoxContainer_->appendVideo(filename_);
}
