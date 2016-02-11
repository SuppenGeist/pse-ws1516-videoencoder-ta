#ifndef __RGBFilterBox_h__
#define __RGBFilterBox_h__

#include <QWidget>
#include <QComboBox>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a rgb filter.
    */
class RGBFilterBox: public FilterConfigurationBox {
    Q_OBJECT
  public:
    /**
     * @brief RGBFilterBox Constructor.
     * @param parent
     */
    RGBFilterBox(QWidget* parent=0);

  protected:
    void updateUi() override;


  private slots:
    void basicColor();
  private:
    QComboBox* rgb_;

    virtual void createFilterOptions();
};
}

#endif


