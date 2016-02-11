#include "RGBFilterBox.h"

#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/RGBFilter.h"
#include "../../utility/BasicColor.h"

GUI::RGBFilterBox::RGBFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
    tempFilter_=std::make_unique<Model::RGBFilter>();

    createFilterOptions();

    connect(rgb_, SIGNAL(currentIndexChanged(int)),this,SLOT( basicColor()));

}

void GUI::RGBFilterBox::updateUi() {
    auto mode_=static_cast<Model::RGBFilter*>(tempFilter_.get())->getColor();

    if(mode_==Model::BasicColor::RED){
    rgb_->setCurrentIndex(0);
    } else if(mode_==Model::BasicColor::GREEN){
    rgb_->setCurrentIndex(1);
    } else if(mode_==Model::BasicColor::BLUE){
    rgb_->setCurrentIndex(2);
    }

    updatePreview();

}

void GUI::RGBFilterBox::basicColor(){
    if(rgb_->currentText()=="RED"){
    static_cast<Model::RGBFilter*>(tempFilter_.get())->setColor(Model::BasicColor::RED);
    } else if(rgb_->currentText()=="GREEN"){
    static_cast<Model::RGBFilter*>(tempFilter_.get())->setColor(Model::BasicColor::GREEN);
    } else if(rgb_->currentText()=="BLUE"){
    static_cast<Model::RGBFilter*>(tempFilter_.get())->setColor(Model::BasicColor::BLUE);
    }
    updatePreview();
}

void GUI::RGBFilterBox::createFilterOptions() {
    QLabel* c=new QLabel("Color:");

    rgb_ = new QComboBox;
    rgb_->addItem("RED");
    rgb_->addItem("GREEN");
    rgb_->addItem("BLUE");

    QHBoxLayout* h_content=new QHBoxLayout;

    h_content->addWidget(c);
    h_content->addWidget(rgb_);

    QFrame* frame=new QFrame;
    frame->setFixedWidth(330);
    frame->setLayout(h_content);
    filterOptionsArea_->setWidget(frame);
}
