#include <exception>

#include "LoadFilterconfig.h"
#include "FilterTab.h"
#include "FilterList.h"
#include "QUndoCommand.h"

LoadFilterconfig::LoadFilterconfig(FilterTab* filterTab, FilterList oldList, FilterList list) {
}

void LoadFilterconfig::undo() {
	throw "Not yet implemented";
}

void LoadFilterconfig::redo() {
	throw "Not yet implemented";
}

