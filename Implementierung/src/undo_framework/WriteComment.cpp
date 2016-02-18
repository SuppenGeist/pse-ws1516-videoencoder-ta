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
