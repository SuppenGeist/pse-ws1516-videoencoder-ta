#ifndef __SharpnessFilterBox_h__
#define __SharpnessFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

#include "FilterConfigurationBox.h"


namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a sharpness filter.
    */
class SharpnessFilterBox: public FilterConfigurationBox
{
    Q_OBJECT
    public:
    /**
     * @brief SharpnessFilterBox Constructor.
     * @param parent
     */
    SharpnessFilterBox(QWidget* parent=0);

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


