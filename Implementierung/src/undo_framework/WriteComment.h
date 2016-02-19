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
	 * @brief undo Reverts changes to the textbox.
	 */
	void undo();


	/**
	 * @brief redo Applies changes to the textbox.
	 */
	void redo();

	/**
	 * @brief mergeWith Trys to merge command with another command.
	 * @param command The other command.
	 * @return If merge was succesfull.
	 */
	bool mergeWith(const QUndoCommand *command);

	/**
	 * @brief id Returns the id of this command.
	 * @return In this case 666
	 */
	int id() const {
		return 666;
	}


  private:
	GUI::AnalysisBoxContainer* container_;
	int index_;
	QString oldComment_;
	QString newComment_;
};
}

#endif

