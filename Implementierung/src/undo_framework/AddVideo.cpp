#include "AddVideo.h"

#include <QUndoCommand>
#include <QString>

#include "../gui/AnalysisBoxContainer.h"


UndoRedo::AddVideo::AddVideo(GUI::AnalysisBoxContainer* anaBoxContainer,QString filename):anaBoxContainer_(anaBoxContainer),filename_(filename) {
}

void UndoRedo::AddVideo::undo() {
    anaBoxContainer_->removeLastVideo();
}

void UndoRedo::AddVideo::redo() {
    anaBoxContainer_->appendVideo(filename_);
}
