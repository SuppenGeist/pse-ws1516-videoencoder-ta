#include "MirrorFilterBox.h"

#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/MirrorFilter.h"
#include "../../model/MirrorMode.h"

GUI::MirrorFilterBox::MirrorFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
    tempFilter_=std::make_unique<Model::MirrorFilter>();

    createFilterOptions();

    connect(horizontal_, SIGNAL(toggled(bool)),this,SLOT(vertical(bool)));
    connect(vertical_, SIGNAL(toggled(bool)),this,SLOT(horizontal(bool)));

}

void GUI::MirrorFilterBox::updateUi()
{
    auto mode_=static_cast<Model::MirrorFilter*>(tempFilter_.get())->getMode();
    if(mode_==Model::MirrorMode::HORIZONTAL){
        horizontal_->setChecked(true);
    } else if (mode_==Model::MirrorMode::VERTICAL){
        vertical_->setChecked(true);
    }
}

void GUI::MirrorFilterBox::vertical(bool on)
{
    if (!on) return;
    static_cast<Model::MirrorFilter*>(tempFilter_.get())->setMode(Model::MirrorMode::VERTICAL);
}

void GUI::MirrorFilterBox::horizontal(bool on)
{
    if (!on) return;
    static_cast<Model::MirrorFilter*>(tempFilter_.get())->setMode(Model::MirrorMode::HORIZONTAL);
}

void GUI::MirrorFilterBox::createFilterOptions()
{
    horizontal_ = new QRadioButton(tr("&HORIZONTAL:"));
    vertical_ = new QRadioButton(tr("&VERTICAL:"));


    QVBoxLayout* h_content=new QVBoxLayout;
    h_content->addWidget(horizontal_);
    h_content->addSpacing(1);
    h_content->addWidget(vertical_);

    QFrame* frame=new QFrame;
    frame->setFixedWidth(330);
    frame->setLayout(h_content);
    filterOptionsArea_->setWidget(frame);
}
