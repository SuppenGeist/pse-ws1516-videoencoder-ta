#include <exception>

#include "RemoveFilter.h"
#include "FilterTab.h"
#include "Filter.h"
#include "QUndoCommand.h"

RemoveFilter::RemoveFilter(FilterTab* filterTab, Filter filter, int index) {
}

void RemoveFilter::undo() {
	throw "Not yet implemented";
}

void RemoveFilter::redo() {
	throw "Not yet implemented";
}

