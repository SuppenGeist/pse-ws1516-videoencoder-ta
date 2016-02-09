#ifndef __BorderFilterBox_h__
#define __BorderFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QCheckBox>
#include <QColorDialog>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a border filter.
    */
    class BorderFilterBox: public FilterConfigurationBox
    {
         Q_OBJECT
            public:
        /**
         * @brief BorderFilterBox Constructor.
         * @param parent
         */
        BorderFilterBox(QWidget* parent=0);

    protected:
        void updateUi() override;


    private slots:

        void sliderChanged(int value);
        void spinBoxChanged(int value);
        void topchecked(int check);
        void bottomchecked(int check);
        void rightchecked(int check);
        void leftchecked(int check);
        void colorChanged(QColor color);

    private:
        QSlider*        slider_;
        QColorDialog*   color_;
        QSpinBox*       spinBox_;
        QCheckBox*      top_;
        QCheckBox*      bottom_;
        QCheckBox*      right_;
        QCheckBox*      left_;

    virtual void createFilterOptions();
    };
}

#endif


