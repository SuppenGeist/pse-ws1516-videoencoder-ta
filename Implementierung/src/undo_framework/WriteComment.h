#ifndef __WriteComment_h__
#define __WriteComment_h__

#include <QUndoCommand>
#include <QPlainTextEdit>
#include <QString>

#include "../gui/AnalysisBoxContainer.h"

namespace UndoRedo {
class WriteComment: public QUndoCommand {
  public:
	/**
	 * @brief WriteComment Constuctor
	 */
    WriteComment(GUI::AnalysisBoxContainer* container,int index,QString oldcomment,QString newComment);


	/**
	 * @brief undo reverts changes to the textbox
	 */
	void undo();


	/**
	 * @brief redo applies changes to the textbox
	 */
	void redo();

  private:
    GUI::AnalysisBoxContainer* container_;
    int index_;
    QString oldComment_;
    QString newComment_;
};
}

#endif

