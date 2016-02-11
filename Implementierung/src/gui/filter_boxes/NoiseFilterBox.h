#ifndef __NoiseFilterBox_h__
#define __NoiseFilterBox_h__

#include <QWidget>
#include <QComboBox>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a noise filter.
    */
class NoiseFilterBox: public FilterConfigurationBox {
    Q_OBJECT
  public:
    /**
     * @brief NoiseFilterBox Constructor.
     * @param parent
     */
    NoiseFilterBox(QWidget* parent=0);

  protected:
    void updateUi() override;


  private slots:
    void noiseMode();
  private:
    QComboBox* combo_;

    virtual void createFilterOptions();
};
}

#endif

