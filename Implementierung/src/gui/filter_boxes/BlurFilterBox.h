#ifndef __BlurFilterBox_h__
#define __BlurFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a blurring filter.
     */
    class BlurFilterBox: public FilterConfigurationBox
    {
        public:
        /**
         * @brief BlurFilterBox Constructor.
         * @param parent
         */
        BlurFilterBox(QWidget* parent=0);

    protected:
        virtual void createFilterOptions();

    private:
        QSlider*     slider_;
        QSpinBox*   spinBox_;
	};
}

#endif
