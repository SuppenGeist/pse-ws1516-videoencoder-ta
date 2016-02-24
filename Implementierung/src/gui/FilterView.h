#ifndef __FilterView_h__
#define __FilterView_h__

#include <memory>

#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QImage>

#include "../model/filters/Filter.h"
#include "FrameView.h"

namespace GUI {
class FilterTab;
class FilterView;
}

namespace GUI {
/**
 * Represents a selectable filter in the gui. Shows an example of the filter and  a checkbox as well as its name.
*/
class FilterView : public QFrame {
	Q_OBJECT

  public:
	/**
	     * @brief FilterView Contructor
	 * @param parent Parent of object
	 */
	FilterView(QWidget* parent=0);

	~FilterView();

	/**
	 * @brief setFilter Sets the filter this view represents.
	 * @param filter The filter for this view.
	 */
	void setFilter(QString filtername);

	/**
	 * @brief setFilterTab Sets the tab this view is contained in.
	 * @param filtertab The parent filtertab.
	 */
	void setFilterTab(FilterTab& filtertab);

  private slots:
	void buttonPressed();

  private:
	static std::unique_ptr<QImage> defaultImage_;

	QPushButton*                    button_addFilter_;
	FilterTab*                      filterTab_;
	FrameView*                      filterView_;
	std::unique_ptr<Model::Filter>  filter_;
	std::unique_ptr<QImage>         filterImage_;

	/**
	 * @brief getDefaultImage Returns the default image on which the filter is applied as a preview.
	 * @return The default image.
	 */
	static QImage& getDefaultImage();

	void createUi();

};
}

#endif

