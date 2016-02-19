#include "AddVideo.h"

#include <QUndoCommand>
#include <QString>

#include "../gui/AnalysisBoxContainer.h"
#include "../gui/AnalysisBox.h"


UndoRedo::AddVideo::AddVideo(GUI::AnalysisBoxContainer* anaBoxContainer,
                             QString filename):anaBoxContainer_(anaBoxContainer),filename_(filename) {
}

void UndoRedo::AddVideo::undo() {
    anaBoxContainer_->removeBox(box_);
}

void UndoRedo::AddVideo::redo() {
    box_=anaBoxContainer_->appendBox(new GUI::AnalysisBox);
    box_->setFile(filename_);
}
