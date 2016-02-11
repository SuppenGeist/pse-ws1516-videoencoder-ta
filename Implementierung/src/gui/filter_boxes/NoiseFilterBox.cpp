#include "NoiseFilterBox.h"

#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/NoiseFilter.h"
#include "../../model/NoiseMode.h"

GUI::NoiseFilterBox::NoiseFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
    tempFilter_=std::make_unique<Model::NoiseFilter>();

    createFilterOptions();

    connect(combo_, SIGNAL(currentIndexChanged(int)),this,SLOT( noiseMode()));

}

void GUI::NoiseFilterBox::updateUi() {
    updateTempFilter();
    auto mode_=static_cast<Model::NoiseFilter*>(tempFilter_.get())->getMode();

    if(mode_==Model::NoiseMode::STATIC){
    combo_->setCurrentIndex(0);
    } else if(mode_==Model::NoiseMode::RANDOM){
    combo_->setCurrentIndex(1);
    } else if(mode_==Model::NoiseMode::MUSTER){
    combo_->setCurrentIndex(2);
    }

    updatePreview();
}

void GUI::NoiseFilterBox::noiseMode(){
    if(combo_->currentText()=="STATIC"){
    static_cast<Model::NoiseFilter*>(tempFilter_.get())->setMode(Model::NoiseMode::STATIC);
    } else if(combo_->currentText()=="RANDOM"){
    static_cast<Model::NoiseFilter*>(tempFilter_.get())->setMode(Model::NoiseMode::RANDOM);
    } else if(combo_->currentText()=="MUSTER"){
    static_cast<Model::NoiseFilter*>(tempFilter_.get())->setMode(Model::NoiseMode::MUSTER);
    }
    updatePreview();
}

void GUI::NoiseFilterBox::createFilterOptions() {
    QLabel* m=new QLabel("Mode:");

    combo_ = new QComboBox;
    combo_->addItem("STATIC");
    combo_->addItem("RANDOM");
    combo_->addItem("MUSTER");

    QHBoxLayout* h_content=new QHBoxLayout;

    h_content->addWidget(m);
    h_content->addWidget(combo_);

    QFrame* frame=new QFrame;
    frame->setFixedWidth(330);
    frame->setLayout(h_content);
    filterOptionsArea_->setWidget(frame);
}
