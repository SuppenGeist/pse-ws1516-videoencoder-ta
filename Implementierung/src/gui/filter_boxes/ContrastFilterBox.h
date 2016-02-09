#ifndef __ContrastFilterBox_h__
#define __ContrastFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a contrast filter.
    */
class ContrastFilterBox: public FilterConfigurationBox
{
    Q_OBJECT
    public:
    /**
     * @brief ContrastFilterBox Constructor.
     * @param parent
    */
    ContrastFilterBox(QWidget* parent=0);

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


