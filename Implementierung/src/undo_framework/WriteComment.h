#ifndef __WriteComment_h__
#define __WriteComment_h__

#include <QUndoCommand>
#include <QTextEdit>

namespace UndoRedo
{
	// class QUndoCommand;
	class WriteComment;
}

namespace UndoRedo
{
    class WriteComment: public QUndoCommand
	{
public:
        /**
         * @brief WriteComment Constuctor
         */
        WriteComment(QTextEdit* textEdit);


        /**
         * @brief undo reverts changes to the textbox
         */
        void undo();


        /**
         * @brief redo applies changes to the textbox
         */
        void redo();

    private:
        QTextEdit* textEdit_;
        bool undoUsed_;
	};
}

#endif

