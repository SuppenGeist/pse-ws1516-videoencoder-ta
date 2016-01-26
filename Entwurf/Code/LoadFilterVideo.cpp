#include <exception>

#include "LoadFilterVideo.h"
#include "FilterTab.h"
#include "FilterTabMemento.h"
#include "YuvVideo.h"
#include "QUndoCommand.h"

LoadFilterVideo::LoadFilterVideo(FilterTab* filterTab, YuvVideo video, FilterTabMemento memento) {
}

void LoadFilterVideo::undo() {
	throw "Not yet implemented";
}

void LoadFilterVideo::redo() {
	throw "Not yet implemented";
}

