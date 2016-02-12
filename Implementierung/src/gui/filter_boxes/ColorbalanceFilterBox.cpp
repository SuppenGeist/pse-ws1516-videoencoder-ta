#include "ColorbalanceFilterBox.h"

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
#include <QLineEdit>

#include "FilterConfigurationBox.h"
#include "../../model/filters/ColorbalanceFilter.h"
#include "../../utility/BasicColor.h"

GUI::ColorbalanceFilterBox::ColorbalanceFilterBox(QWidget* parent) {
    tempFilter_=std::make_unique<Model::ColorbalanceFilter>();

    createFilterOptions();

    connect(bright_, SIGNAL(stateChanged(int)),this,SLOT(brightPixel(int)));
    connect(medium_, SIGNAL(stateChanged(int)),this,SLOT(mediumPixel(int)));
    connect(dark_, SIGNAL(stateChanged(int)),this,SLOT(darkPixel(int)));
    connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
    connect(slider_,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    connect(combo_, SIGNAL(currentIndexChanged(int)),this,SLOT( basicColor()));

}

void GUI::ColorbalanceFilterBox::updateUi() {
    updateTempFilter();
    auto bright=static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->getBrightPixels();
    auto medium=static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->getMediumPixels();
    auto dark=static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->getDarkPixels();
    auto value=static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->getIntensity();
    auto mode_=static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->getColor();


    bright_->setChecked(bright);
    medium_->setChecked(medium);
    dark_->setChecked(dark);
    slider_->setValue(value);
    spinBox_->setValue(value);
    if(mode_==Model::BasicColor::RED){
    combo_->setCurrentIndex(0);
    } else if(mode_==Model::BasicColor::GREEN){
    combo_->setCurrentIndex(1);
    } else if(mode_==Model::BasicColor::BLUE){
    combo_->setCurrentIndex(2);
    }

    updatePreview();
}


void GUI::ColorbalanceFilterBox::sliderChanged(int value) {
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setIntensity(value);
    spinBox_->setValue(value);
}

void GUI::ColorbalanceFilterBox::spinBoxChanged(int value) {
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setIntensity(value);
    slider_->setValue(value);
    updatePreview();
}


void GUI::ColorbalanceFilterBox::brightPixel(int check) {
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setBrightPixels(check);
    bright_->setChecked(check);

    updatePreview();
}

void GUI::ColorbalanceFilterBox::mediumPixel(int check) {
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setMediumPixels(check);
    medium_->setChecked(check);

    updatePreview();
}

void GUI::ColorbalanceFilterBox::darkPixel(int check) {
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setDarkPixels(check);
    dark_->setChecked(check);

    updatePreview();
}


void GUI::ColorbalanceFilterBox::basicColor(){
    if(combo_->currentText()=="RED"){
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setColor(Model::BasicColor::RED);
    } else if(combo_->currentText()=="GREEN"){
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setColor(Model::BasicColor::GREEN);
    } else if(combo_->currentText()=="BLUE"){
    static_cast<Model::ColorbalanceFilter*>(tempFilter_.get())->setColor(Model::BasicColor::BLUE);
    }
    updatePreview();
}

void GUI::ColorbalanceFilterBox::createFilterOptions() {
    QLabel* i=new QLabel("Intensity:");
    QLabel* b=new QLabel("Bright");
    QLabel* m=new QLabel("Medium");
    QLabel* d=new QLabel("Dark");

    bright_= new QCheckBox;
    medium_= new QCheckBox;
    dark_= new QCheckBox;

    slider_=new QSlider(Qt::Horizontal);
    slider_->setMaximum(100);
    slider_->setMinimum(0);

    spinBox_=new QSpinBox;
    spinBox_->setMaximum(100);
    spinBox_->setMinimum(0);

    combo_ = new QComboBox;
    combo_->addItem("RED");
    combo_->addItem("GREEN");
    combo_->addItem("BLUE");
    combo_->setFixedWidth(100);

    QVBoxLayout* h_content=new QVBoxLayout;
    QHBoxLayout* topLayout=new QHBoxLayout;
    QHBoxLayout* bottomLayout=new QHBoxLayout;
    QHBoxLayout* bottom2Layout= new QHBoxLayout;

    topLayout->addWidget(b);
    topLayout->addWidget(bright_);
    QFrame* separator1=new QFrame;
    separator1->setFrameShape(QFrame::VLine);
    separator1->setFrameShadow(QFrame::Sunken);
    topLayout->addWidget(separator1);
    topLayout->addWidget(m);
    topLayout->addWidget(medium_);
    QFrame* separator2=new QFrame;
    separator2->setFrameShape(QFrame::VLine);
    separator2->setFrameShadow(QFrame::Sunken);
    topLayout->addWidget(separator2);
    topLayout->addWidget(d);
    topLayout->addWidget(dark_);

    QLabel* label_color=new QLabel("Color:");
    bottomLayout->addWidget(label_color);
    bottomLayout->addWidget(combo_);

    bottom2Layout->addWidget(i);
    bottom2Layout->addWidget(slider_);
    bottom2Layout->addWidget(spinBox_);


    h_content->addSpacing(5);
    h_content->addLayout(topLayout);
    QFrame* separator3=new QFrame;
    separator3->setFrameShape(QFrame::HLine);
    separator3->setFrameShadow(QFrame::Plain);
    separator3->setStyleSheet("background-color:black;");
    separator3->setFixedHeight(1);
    h_content->addSpacing(5);
    h_content->addWidget(separator3);
    h_content->addSpacing(5);
    h_content->addLayout(bottomLayout);
    QFrame* separator4=new QFrame;
    separator4->setFrameShape(QFrame::HLine);
    separator4->setFrameShadow(QFrame::Plain);
    separator4->setStyleSheet("background-color:black;");
    separator4->setFixedHeight(1);
    h_content->addSpacing(5);
    h_content->addWidget(separator4);
    h_content->addSpacing(5);
    h_content->addLayout(bottom2Layout);
    h_content->addSpacing(5);

    QFrame* frame=new QFrame;
    frame->setFixedWidth(330);
    frame->setLayout(h_content);
    filterOptionsArea_->setWidget(frame);
}
