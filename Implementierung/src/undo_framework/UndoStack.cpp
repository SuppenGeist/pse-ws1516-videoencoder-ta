#include "UndoStack.h"

#include <QUndoStack>

QUndoStack UndoRedo::UndoStack::undoStack_;

UndoRedo::UndoStack::UndoStack() {

}

QUndoStack& UndoRedo::UndoStack::getUndoStack() {
    return undoStack_;
}
