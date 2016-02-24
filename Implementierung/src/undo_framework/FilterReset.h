#ifndef __FilterReset_h__
#define __FilterReset_h__

#include <QUndoCommand>

#include <memory>

#include "../memento/FilterTabMemento.h"

namespace GUI {
class FilterTab;
}

namespace Model {
class FilterList;
}

namespace UndoRedo {
/**
 * This class is the undo command for resetting the filterlist in the filter tab.
 */
class FilterReset: public QUndoCommand {
  public:
	/**
	 * @brief FilterReset Constructor.
	 * @param filterTab The filtertab to operate on.
	 * @param filterList The filterlist the action to perform on.
	 */
	FilterReset(GUI::FilterTab& filterTab);

	/**
	     * @brief undo Loads the filterlist and filter configuration to the state it was before the reset.
	     */
	void undo();

	/**
	 * @brief redo Clears the filter configurations and the filter list.
	     */
	void redo();

  private:
	GUI::FilterTab*                     filterTab_;
	std::unique_ptr<Model::FilterList>  filterList_;
	std::unique_ptr<Memento::FilterTabMemento>  memento_;
};
}

#endif
