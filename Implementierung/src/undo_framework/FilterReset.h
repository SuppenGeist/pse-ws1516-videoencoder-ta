#ifndef __FilterReset_h__
#define __FilterReset_h__

#include <QUndoCommand>

#include <memory>

namespace GUI {
class FilterTab;
}

namespace Model {
class FilterList;
}

namespace UndoRedo {
/**
 * This class is the undo command for resting the filterlist in the filter tab.
 */
class FilterReset: public QUndoCommand {
  public:
	/**
	 * @brief FilterReset Constructor.
	 * @param filterTab The filtertab to operate on.
	 * @param filterList The filterlist the action to perform on.
	 */
	FilterReset(GUI::FilterTab& filterTab, std::unique_ptr<Model::FilterList> filterList);

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
};
}

#endif
