#ifndef __PosterFilterBox_h__
#define __PosterFilterBox_h__

#include <QWidget>
#include <QSpinBox>

#include "FilterConfigurationBox.h"

namespace GUI {
/**
 * This class contains the gui elements for changing the options of a poster filter.
*/
class PosterFilterBox: public FilterConfigurationBox {
	Q_OBJECT
  public:
	/**
	 * @brief PosterFilterBox Constructor.
	 * @param parent
	*/
	PosterFilterBox(QWidget* parent=0);

  protected:
	void updateUi() override;

  private slots:
	void spinBoxChanged(int value);
  private:
	QSpinBox*   spinBox_;

	virtual void createFilterOptions();
};
}

#endif

