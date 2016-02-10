#ifndef __ScaleFilterBox_h__
#define __ScaleFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QCheckBox>

#include "FilterConfigurationBox.h"

namespace GUI {
/**
 * This class contains the gui elements for changing the options of a scale filter.
*/
class ScaleFilterBox: public FilterConfigurationBox {
	Q_OBJECT
  public:
	/**
	 * @brief ScaleFilterBox Constructor.
	 * @param parent
	 */
	ScaleFilterBox(QWidget* parent=0);

  protected:
	void updateUi() override;


  private slots:
	void heightChanged(int value);
	void widthChanged(int value);
	void ratioChanged(int value);
	void keepRatio(int check);
  private:
	QSpinBox*       width_;
	QSpinBox*       height_;
	QSpinBox* ratio_;
	QCheckBox*      keepRatio_;

	virtual void createFilterOptions();
};
}

#endif


