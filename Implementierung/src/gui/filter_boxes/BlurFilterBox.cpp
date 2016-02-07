#include "BlurFilterBox.h"

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "FilterConfigurationBox.h"
#include "../../model/filters/BlurFilter.h"

GUI::BlurFilterBox::BlurFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
    tempFilter_=std::make_unique<Model::BlurFilter>();
    FilterConfigurationBox::setLayout(h_content);
}

void GUI::BlurFilterBox::createFilterOptions()
{

}
