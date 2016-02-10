#ifndef __GridFilterBox_h__
#define __GridFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

#include "FilterConfigurationBox.h"

namespace GUI {
/**
 * This class contains the gui elements for changing the options of a grid filter.
*/
class GridFilterBox: public FilterConfigurationBox {
	Q_OBJECT
  public:
	/**
	 * @brief GridFilterBox Constructor.
	 * @param parent
	 */
	GridFilterBox(QWidget* parent=0);

  protected:
	void updateUi() override;


  private slots:
	void spinBoxChanged(int value);
	void slider2Changed(int value2);
	void spinBox2Changed(int value2);
	void spinBox3Changed(int value3);
	void spinBox4Changed(int value4);
	void openColorDialog();
  private:
	QSlider*        slider2_;
	QSpinBox*       spinBox_;
	QSpinBox*       spinBox2_;
	QSpinBox*       spinBox3_;
	QSpinBox*       spinBox4_;
	QPushButton*    button_;

	virtual void createFilterOptions();
};
}

#endif


