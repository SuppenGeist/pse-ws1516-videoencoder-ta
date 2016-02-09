#include "BorderFilterBox.h"
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
#include "../../model/filters/BorderFilter.h"

GUI::BorderFilterBox::BorderFilterBox(QWidget* parent) {
    tempFilter_=std::make_unique<Model::BorderFilter>();

    createFilterOptions();

    connect(top_, SIGNAL(stateChanged(int)),this,SLOT(topchecked(int)));
    connect(bottom_, SIGNAL(stateChanged(int)),this,SLOT(bottomchecked(int)));
    connect(right_, SIGNAL(stateChanged(int)),this,SLOT(rightchecked(int)));
    connect(left_, SIGNAL(stateChanged(int)),this,SLOT(leftchecked(int)));
    connect(slider_,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
    //connect(color_,SIGNAL(currentColorChanged(QColor)),this,SLOT(sliderChanged(int)));

}

void GUI::BorderFilterBox::updateUi()
{
    auto top=static_cast<Model::BorderFilter*>(tempFilter_.get())->getTop();
    auto bottom=static_cast<Model::BorderFilter*>(tempFilter_.get())->getBottom();
    auto right=static_cast<Model::BorderFilter*>(tempFilter_.get())->getRight();
    auto left=static_cast<Model::BorderFilter*>(tempFilter_.get())->getLeft();
    auto value=static_cast<Model::BorderFilter*>(tempFilter_.get())->getThickness();
    //auto color=static_cast<Model::BorderFilter*>(tempFilter_.get())->getColor();

    top_->setChecked(top);
    bottom_->setChecked(bottom);
    right_->setChecked(right);
    left_->setChecked(left);
    slider_->setValue(value);
    spinBox_->setValue(value);
    //color_->setCurrentColor(color);
}

void GUI::BorderFilterBox::sliderChanged(int value)
{
    static_cast<Model::BorderFilter*>(tempFilter_.get())->setThickness(value);
    spinBox_->setValue(value);
}

void GUI::BorderFilterBox::spinBoxChanged(int value)
{
    static_cast<Model::BorderFilter*>(tempFilter_.get())->setThickness(value);
    slider_->setValue(value);

    updatePreview();
}

void GUI::BorderFilterBox::colorChanged(QColor color)
{
    static_cast<Model::BorderFilter*>(tempFilter_.get())->setColor(color);
    color_->setCurrentColor(color);
}


void GUI::BorderFilterBox::topchecked(int check)
{
    static_cast<Model::BorderFilter*>(tempFilter_.get())->setTop(check);
    top_->setChecked(check);

    updatePreview();
}

void GUI::BorderFilterBox::bottomchecked(int check)
{
    static_cast<Model::BorderFilter*>(tempFilter_.get())->setBottom(check);
    bottom_->setChecked(check);

    updatePreview();
}

void GUI::BorderFilterBox::rightchecked(int check)
{
    static_cast<Model::BorderFilter*>(tempFilter_.get())->setRight(check);
    right_->setChecked(check);

    updatePreview();
}

void GUI::BorderFilterBox::leftchecked(int check)
{
    static_cast<Model::BorderFilter*>(tempFilter_.get())->setLeft(check);
    left_->setChecked(check);

    updatePreview();
}

void GUI::BorderFilterBox::createFilterOptions()
{
    QLabel* l=new QLabel("Intensity:");
    QLabel* t=new QLabel("Top");
    QLabel* b=new QLabel("Bottom");
    QLabel* r=new QLabel("Right");
    QLabel* le=new QLabel("Left");
    top_= new QCheckBox;
    bottom_= new QCheckBox;
    right_= new QCheckBox;
    left_= new QCheckBox;

    slider_=new QSlider(Qt::Horizontal);
    slider_->setMaximum(100);
    slider_->setMinimum(0);

    spinBox_=new QSpinBox;
    spinBox_->setMaximum(100);
    spinBox_->setMinimum(0);

    //color_ =new QColorDialog;

    QVBoxLayout* h_content=new QVBoxLayout;
    QHBoxLayout* topLayout=new QHBoxLayout;
    QHBoxLayout* bottomLayout=new QHBoxLayout;
    //QHBoxLayout* bottom2Layout= new QHBoxLayout;

    topLayout->addWidget(t);
    topLayout->addWidget(top_);
    topLayout->addWidget(b);
    topLayout->addWidget(bottom_);
    topLayout->addWidget(r);
    topLayout->addWidget(right_);
    topLayout->addWidget(le);
    topLayout->addWidget(left_);
    bottomLayout->addWidget(l);
    bottomLayout->addWidget(slider_);
    bottomLayout->addWidget(spinBox_);
    //bottom2Layout->addWidget(color_);

    h_content->addLayout(topLayout);
    h_content->addLayout(bottomLayout);
    //h_content->addLayout(bottom2Layout);

    QFrame* frame=new QFrame;
    frame->setFixedWidth(330);
    frame->setLayout(h_content);
    filterOptionsArea_->setWidget(frame);
}
