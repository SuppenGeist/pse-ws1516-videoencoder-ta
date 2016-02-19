#include "WriteComment.h"

#include <QUndoCommand>

UndoRedo::WriteComment::WriteComment(GUI::AnalysisBoxContainer *container, int index, QString oldcomment, QString newComment):container_(container),index_(index),oldComment_(oldcomment),newComment_(newComment) {

}

void UndoRedo::WriteComment::undo() {
    auto textEdit=container_->getAnalysisBox(index_)->getCommentBox();
    textEdit->blockSignals(true);
    textEdit->document()->setPlainText(oldComment_);
    textEdit->blockSignals(false);
}

void UndoRedo::WriteComment::redo() {
        auto textEdit=container_->getAnalysisBox(index_)->getCommentBox();
        textEdit->blockSignals(true);
        textEdit->document()->setPlainText(newComment_);
        textEdit->blockSignals(false);
}
bool UndoRedo::WriteComment::mergeWith(const QUndoCommand *command) {
    const UndoRedo::WriteComment* writeCommand = static_cast<const UndoRedo::WriteComment*>(command);

         if ((newComment_.split(" ").size() != writeCommand->newComment_.split(" ").size()))
            return false;

         newComment_ = writeCommand->newComment_;

         return true;
}

