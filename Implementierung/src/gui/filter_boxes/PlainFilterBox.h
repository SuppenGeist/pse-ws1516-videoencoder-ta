#ifndef __PlainFilterBox_h__
#define __PlainFilterBox_h__

#include <QWidget>

#include "FilterConfigurationBox.h"

namespace GUI {
/**
 * This class contains no sliders to adjust filter options.
 */
class PlainFilterBox: public FilterConfigurationBox {
  public:
	/**
	 * @brief PlainFilterBox Constructor.
	 * @param parent
	 */
	PlainFilterBox(QWidget* parent=0);

  protected:
	void updateUi();
};
}

#endif
