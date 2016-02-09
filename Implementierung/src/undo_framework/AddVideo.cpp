#include "AddVideo.h"

#include <QUndoCommand>

#include "../gui/AnalysisBox.h"
#include "../gui/AnalysisBoxContainer.h"


UndoRedo::AddVideo::AddVideo(GUI::AnalysisBox*) {
}

void UndoRedo::AddVideo::undo() {
	throw "Not yet implemented";
}

void UndoRedo::AddVideo::redo() {
	throw "Not yet implemented";
}
