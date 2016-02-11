#ifndef __LoadFilterconfig_h__
#define __LoadFilterconfig_h__

#include <QUndoCommand>

#include <memory>

namespace Model {
class FilterList;
}

namespace GUI {
class FilterTab;
}

namespace UndoRedo {
/**
 * This class is the undo command for loading a filter config on the filter tab.
 */
class LoadFilterconfig: public QUndoCommand {
  public:
	/**
	 * @brief LoadFilterconfig Constuctor.
	 * @param filterTab The filtertab to operate on.
	 * @param oldList The filterlist before the config is loaded.
	 * @param list The new filter configuration.
	 */
    LoadFilterconfig(GUI::FilterTab& filterTab, std::unique_ptr<Model::FilterList> oldList,std::unique_ptr<Model::FilterList> newList);

	/**
	 * @brief undo Loads the filter configuration present before external configuration was loaded.
	 */
	void undo();

	/**
	 * @brief redo Loads a filter configuration from a external file.
	 */
	void redo();

  private:
	GUI::FilterTab*                     filterTab_;
	std::unique_ptr<Model::FilterList>  oldList_;
	std::unique_ptr<Model::FilterList>  newList_;
};
}

#endif
