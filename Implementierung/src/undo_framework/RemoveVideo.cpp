#include "RemoveVideo.h"

#include <QUndoCommand>

#include "../gui/AnalysisBox.h"
#include "../gui/AnalysisBoxContainer.h"
#include "../memento/AnalysisBoxMemento.h"

UndoRedo::RemoveVideo::RemoveVideo(GUI::AnalysisBox* box){
    anaBox = box;
    boxMemo = box->getMemento();
    container = (GUI::AnalysisBoxContainer*) box->parent();
}

void UndoRedo::RemoveVideo::undo() {
    anaBox = container->addBox(index, boxMemo);
}

void UndoRedo::RemoveVideo::redo() {
    index = ((GUI::AnalysisBoxContainer*) anaBox->parent())->removeBox(anaBox);
}
