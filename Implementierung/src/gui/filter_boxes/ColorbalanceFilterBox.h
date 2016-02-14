#ifndef __ColorbalanceFilterBox_h__
#define __ColorbalanceFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QCheckBox>
#include <QComboBox>

#include "FilterConfigurationBox.h"

namespace GUI {
/**
 * This class contains the gui elements for changing the options of a color balance filter.
*/
class ColorbalanceFilterBox: public FilterConfigurationBox {
	Q_OBJECT
  public:
	/**
	 * @brief ColorbalanceFilterBox Constructor.
	 * @param parent
	 */
	ColorbalanceFilterBox(QWidget* parent=0);

  protected:
	void updateUi() override;


  private slots:
	void spinBoxChanged(int value);
	void sliderChanged(int value);
	void brightPixel(int check);
	void mediumPixel(int check);
	void darkPixel(int check);
	void basicColor();

  private:
	QSpinBox*       spinBox_;
	QSlider*        slider_;
	QCheckBox*      bright_;
	QCheckBox*      medium_;
	QCheckBox*      dark_;
	QComboBox*      combo_;

	virtual void createFilterOptions();
};
}

#endif


