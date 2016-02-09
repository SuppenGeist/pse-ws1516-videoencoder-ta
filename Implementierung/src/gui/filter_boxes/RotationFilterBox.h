#ifndef __RotationFilterBox_h__
#define __RotationFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a rotation filter.
    */
class RotationFilterBox: public FilterConfigurationBox
{
    Q_OBJECT
    public:
    /**
     * @brief RotationFilterBox Constructor.
     * @param parent
    */
    RotationFilterBox(QWidget* parent=0);

protected:
    void updateUi() override;

private slots:
    void sliderChanged(int value);
    void spinBoxChanged(int value);
private:
    QSlider*     slider_;
    QSpinBox*   spinBox_;

    virtual void createFilterOptions();
};
}

#endif


