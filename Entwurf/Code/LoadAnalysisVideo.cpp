#include <exception>

#include "LoadAnalysisVideo.h"
#include "AnalysisTab.h"
#include "AnalysisTabMemento.h"
#include "YuvVideo.h"
#include "QUndoCommand.h"

LoadAnalysisVideo::LoadAnalysisVideo(AnalysisTab* anaTab, AnalyseTabMemento anaTabMem, YuvVideo video) {
}

void LoadAnalysisVideo::undo() {
	throw "Not yet implemented";
}

void LoadAnalysisVideo::redo() {
	throw "Not yet implemented";
}

