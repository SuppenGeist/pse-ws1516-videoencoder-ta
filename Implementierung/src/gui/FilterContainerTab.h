#ifndef __FilterContainerTab_h__
#define __FilterContainerTab_h__

#include <string>
#include <vector>
#include <QFrame>
#include <QWidget>

#include "FilterTab.h"
#include "FilterView.h"

namespace GUI {
class FilterTab;
class FilterView;
}
namespace Model {
class Filter;
}
namespace Ui {
class FilterContainerTab;
}

namespace GUI {
/**
 * This class shows all the selectable filters.
*/
class FilterContainerTab : public QFrame {
  public:

	/**
	 * @brief FilterContainerTab constructor
	 * @param parent parent of this object
	 */
	FilterContainerTab(QWidget* parent=0);

	/**
	 * @brief addFilter Adds a selectable filter.
	 * @param filter The new filter.
	 */
	void addFilter(Model::Filter* filter);

	/**
	 * @brief setParentTab Sets the parent tab.
	 * @param parent The parent tab.
	 */
	void setParentTab(GUI::FilterTab& parent);

	/**
	 * @brief uncheck Searches for the filterView with the filter filterName and unchecks it.
	 * @param filterName The filter to uncheck.
	 */
	void uncheck(std::string filterName);

  private:
	GUI::FilterTab* parentTab;
	GUI::FilterTab* filterContainerTab;
	std::vector<GUI::FilterView*> filterViews;
	Ui::FilterContainerTab* ui;
};
}

#endif

