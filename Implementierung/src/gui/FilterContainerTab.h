#ifndef __FilterContainerTab_h__
#define __FilterContainerTab_h__

#include <vector>

#include <QFrame>
#include <QWidget>
#include <QHBoxLayout>
#include <QString>
#include <QVBoxLayout>

namespace GUI {
class FilterTab;
class FilterView;
}
namespace Model {
class Filter;
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
	void addFilter(QString filtername);

	/**
	 * @brief setParentTab Sets the parent tab.
	 * @param parent The parent tab.
	 */
	void setParentTab(FilterTab& parent);

  private:
	FilterTab*                  parentTab_;
	QHBoxLayout*                container_;
	QHBoxLayout*                filterContainer_;
	std::vector<FilterView*>    filterViews_;

	void createUi();
};
}

#endif

