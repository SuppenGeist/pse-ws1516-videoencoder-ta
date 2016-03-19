#ifndef __MoveFilterUp_h__
#define __MoveFilterUp_h__

#include <QUndoCommand>

#include <memory>

namespace GUI {
class FilterTab;
}

namespace UndoRedo {
/**
 * This class is the undo command for moving a filter up in the filterlist.
 */
class MoveFilterUp: public QUndoCommand {

  public:
	/**
	 * @brief MoveFilterUp Constructor.
	 * @param filterTab The filtertab to operate on.
	 * @param old Old index of the filter.
	 * @param new_1 New index of the filter.
	 */
	MoveFilterUp(GUI::FilterTab& filterTab, int index);

	/**
	 * @brief undo Moves the filter one position back down in the filterlist.
	 */
	void undo();

	/**
	 * @brief redo Moves selected filter one position up in the filterlist.
	 */
	void redo();

  private:
	int             index_;
    GUI::FilterTab* filterTab_;
};
}

#endif
