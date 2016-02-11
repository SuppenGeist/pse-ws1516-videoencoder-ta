#ifndef __RectangleFilterBox_h__
#define __RectangleFilterBox_h__

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QColorDialog>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a rectangle filter.
    */
class RectangleFilterBox: public FilterConfigurationBox {
    Q_OBJECT
  public:
    /**
     * @brief BorderFilterBox Constructor.
     * @param parent
     */
    RectangleFilterBox(QWidget* parent=0);

  protected:
    void updateUi() override;


  private slots:
    void sliderChanged(int value);
    void spinBoxChanged(int value);
    void widthChanged(int value);
    void heightChanged(int value);
    void xChanged(int value);
    void yChanged(int value);
    void openColorDialog();

  private:
    QSlider*        slider_;
    QSpinBox*       spinBox_;
    QSpinBox*       width_;
    QSpinBox*       height_;
    QSpinBox*       x_;
    QSpinBox*       y_;
    QPushButton*    button_;
    QColor          color_;

    virtual void createFilterOptions();
};
}

#endif


