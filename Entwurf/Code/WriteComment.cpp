#include <exception>

#include "WriteComment.h"
#include "QUndoCommand.h"

WriteComment::WriteComment() {
}

void WriteComment::mergeWith(QUndoCommand command) {
	throw "Not yet implemented";
}

void WriteComment::undo() {
	throw "Not yet implemented";
}

void WriteComment::redo() {
	throw "Not yet implemented";
}

void WriteComment::id() {
	throw "Not yet implemented";
}

