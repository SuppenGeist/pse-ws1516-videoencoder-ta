#include <exception>

#include "AddVideo.h"
#include "AnalysisBox.h"
#include "AnalysisBoxContainer.h"
#include "EncodedVideo.h"
#include "QUndoCommand.h"

AddVideo::AddVideo(AnalysisBoxContainer* analysisBoxContainer, EncodedVideo video) {
}

void AddVideo::undo() {
	throw "Not yet implemented";
}

void AddVideo::redo() {
	throw "Not yet implemented";
}

