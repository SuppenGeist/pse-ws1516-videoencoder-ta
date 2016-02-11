#ifndef __BorderFilterBox_h__
#define __BorderFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QCheckBox>
#include <QColorDialog>

#include "FilterConfigurationBox.h"

namespace GUI {
/**
 * This class contains the gui elements for changing the options of a border filter.
*/
class BorderFilterBox: public FilterConfigurationBox {
	Q_OBJECT
  public:
	/**
	 * @brief BorderFilterBox Constructor.
	 * @param parent
	 */
	BorderFilterBox(QWidget* parent=0);

  protected:
	void updateUi() override;


  private slots:
	void spinBoxChanged(int value);
	void topchecked(int check);
	void bottomchecked(int check);
	void rightchecked(int check);
	void leftchecked(int check);
	void openColorDialog();

  private:
	QSpinBox*       spinBox_;
	QCheckBox*      top_;
	QCheckBox*      bottom_;
	QCheckBox*      right_;
	QCheckBox*      left_;
	QPushButton*    button_;
    QPalette*       pal;
    QColor          color_;

	virtual void createFilterOptions();
};
}

#endif


