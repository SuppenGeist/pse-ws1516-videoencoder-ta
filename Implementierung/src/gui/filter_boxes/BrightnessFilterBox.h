#ifndef __BrightnessFilterBox_h__
#define __BrightnessFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a brightness filter.
     */
    class BrightnessFilterBox: public FilterConfigurationBox
    {
        Q_OBJECT
        public:
        /**
         * @brief BrightnessFilterBox Constructor.
         * @param parent
        */
        BrightnessFilterBox(QWidget* parent=0);

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


