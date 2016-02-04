#ifndef __UndoStack_h__
#define __UndoStack_h__

#include <QUndoStack>

namespace UndoRedo {
/**
 * This class holds the stack that all undo commands are stacked on as a singleton.
*/
class UndoStack {
  public:
	/**
	 * @brief getUndoStack Returns the undo stack to operate on.
	 * @return The undo stack.
	 */
	static QUndoStack& getUndoStack();

  private:
	static QUndoStack undoStack_;

	/**
	 * @brief UndoStack Constructor.
	 */
	UndoStack();
};
}

#endif

