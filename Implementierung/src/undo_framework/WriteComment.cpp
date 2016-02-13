#include "WriteComment.h"

#include <QUndoCommand>

UndoRedo::WriteComment::WriteComment(QTextEdit* textEdit) {
    textEdit_ = textEdit;
    undoUsed_ = false;
}

void UndoRedo::WriteComment::undo() {
    textEdit_->blockSignals(true);
    textEdit_->undo();
    textEdit_->blockSignals(false);
    undoUsed_ = true;
}

void UndoRedo::WriteComment::redo() {
    if(undoUsed_) {
    textEdit_->blockSignals(true);
    textEdit_->redo();
    textEdit_->blockSignals(false);
    }
}
