#include "RectangleFilterBox.h"

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QCheckBox>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/RectangleFilter.h"

GUI::RectangleFilterBox::RectangleFilterBox(QWidget* parent) {
    tempFilter_=std::make_unique<Model::RectangleFilter>();

    createFilterOptions();

    connect(slider_,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
    connect(width_,SIGNAL(valueChanged(int)),this,SLOT(widthChanged(int)));
    connect(height_,SIGNAL(valueChanged(int)),this,SLOT(heightChanged(int)));
    connect(x_,SIGNAL(valueChanged(int)),this,SLOT(xChanged(int)));
    connect(y_,SIGNAL(valueChanged(int)),this,SLOT(yChanged(int)));
    connect(button_,SIGNAL(clicked()),this,SLOT(openColorDialog()));
}

void GUI::RectangleFilterBox::updateUi() {
    updateTempFilter();

    auto value=static_cast<Model::RectangleFilter*>(tempFilter_.get())->getOpacity();
    auto height=static_cast<Model::RectangleFilter*>(tempFilter_.get())->getHeight();
    auto width=static_cast<Model::RectangleFilter*>(tempFilter_.get())->getWidth();
    auto x=static_cast<Model::RectangleFilter*>(tempFilter_.get())->getX();
    auto y=static_cast<Model::RectangleFilter*>(tempFilter_.get())->getY();
    auto color=static_cast<Model::RectangleFilter*>(tempFilter_.get())->getColor();

    color_=color;
    spinBox_->setValue(value);
    slider_->setValue(value);
    height_->setValue(height);
    width_->setValue(width);
    x_->setValue(x);
    y_->setValue(y);

    updatePreview();
}

void GUI::RectangleFilterBox::openColorDialog() {
    color_ = QColorDialog::getColor(color_,this);
    static_cast<Model::RectangleFilter*>(tempFilter_.get())->setColor(color_);
    updatePreview();
}

void GUI::RectangleFilterBox::sliderChanged(int value) {
    static_cast<Model::RectangleFilter*>(tempFilter_.get())->setOpacity(value);
    spinBox_->setValue(value);
}

void GUI::RectangleFilterBox::spinBoxChanged(int value) {
    static_cast<Model::RectangleFilter*>(tempFilter_.get())->setOpacity(value);
    slider_->setValue(value);

    updatePreview();
}

void GUI::RectangleFilterBox::widthChanged(int value) {
    static_cast<Model::RectangleFilter*>(tempFilter_.get())->setWidth(value);

    updatePreview();
}

void GUI::RectangleFilterBox::heightChanged(int value) {
    static_cast<Model::RectangleFilter*>(tempFilter_.get())->setHeight(value);

    updatePreview();
}

void GUI::RectangleFilterBox::xChanged(int value) {
    static_cast<Model::RectangleFilter*>(tempFilter_.get())->setX(value);

    updatePreview();
}

void GUI::RectangleFilterBox::yChanged(int value) {
    static_cast<Model::RectangleFilter*>(tempFilter_.get())->setY(value);

    updatePreview();
}

void GUI::RectangleFilterBox::createFilterOptions() {
    QLabel* h=new QLabel("Height:");
    QLabel* w=new QLabel("Width:");
    QLabel* x=new QLabel("X:");
    QLabel* y=new QLabel("Y:");
    QLabel* o=new QLabel("Opacity:");

    button_ = new QPushButton(tr("Color"));

    QColor color_;

    slider_=new QSlider(Qt::Horizontal);
    slider_->setMaximum(255);
    slider_->setMinimum(0);

    spinBox_=new QSpinBox;
    spinBox_->setMaximum(255);
    spinBox_->setMinimum(0);

    height_=new QSpinBox();
    height_->setMaximum(100000);
    height_->setMinimum(0);

    width_=new QSpinBox;
    width_->setMaximum(100000);
    width_->setMinimum(0);

    x_=new QSpinBox();
    x_->setMaximum(100000);
    x_->setMinimum(0);

    y_=new QSpinBox;
    y_->setMaximum(100000);
    y_->setMinimum(0);

    QVBoxLayout* h_content=new QVBoxLayout;
    QHBoxLayout* wh=new QHBoxLayout;
    QHBoxLayout* xy=new QHBoxLayout;
    QHBoxLayout* op=new QHBoxLayout;
    QHBoxLayout* co=new QHBoxLayout;

    wh->addWidget(h);
    wh->addWidget(height_);
    wh->addWidget(w);
    wh->addWidget(width_);

    xy->addWidget(x);
    xy->addWidget(x_);
    xy->addWidget(y);
    xy->addWidget(y_);

    op->addWidget(o);
    op->addWidget(slider_);
    op->addWidget(spinBox_);

    co->addWidget(button_);

    h_content->addLayout(wh);
    h_content->addSpacing(5);
    h_content->addLayout(xy);
    h_content->addSpacing(5);
    h_content->addLayout(op);
    h_content->addSpacing(5);
    h_content->addLayout(co);

    QFrame* frame=new QFrame;
    frame->setFixedWidth(330);
    frame->setLayout(h_content);
    filterOptionsArea_->setWidget(frame);
}
