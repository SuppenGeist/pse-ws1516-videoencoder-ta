#include "FilterConfigurationBox.h"

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QImage>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <QScrollArea>
#include <QLabel>
#include <QDebug>

#include "../../model/filters/Filter.h"
#include "../FrameView.h"

#include "BlurFilterBox.h"
#include "PlainFilterBox.h"

#include "../../model/filters/BlurFilter.h"

std::unique_ptr<QImage> GUI::FilterConfigurationBox::defaultImage_;

GUI::FilterConfigurationBox::FilterConfigurationBox(QWidget* parent):QFrame(parent) {
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    createUi();

}

GUI::FilterConfigurationBox::~FilterConfigurationBox()
{

}

std::unique_ptr<GUI::FilterConfigurationBox> GUI::FilterConfigurationBox::CreateConfigurationBox(Model::Filter &filter) {
    std::unique_ptr<FilterConfigurationBox> box;

    if(filter.getName()==Model::BlurFilter::FILTERNAME) {
        box=std::make_unique<BlurFilterBox>();
    }else {
        box=std::make_unique<PlainFilterBox>();
    }

    box->setFilter(filter);
    box->createUi();

    return std::move(box);
}

void GUI::FilterConfigurationBox::setFilter(Model::Filter& filter) {
    filter_=&filter;
    tempFilter_->restoreFilter(filter.getSaveString());
}

Model::Filter* GUI::FilterConfigurationBox::getFilter() {
    return filter_;
}

void GUI::FilterConfigurationBox::updatePreview()
{

}

void GUI::FilterConfigurationBox::createFilterOptions()
{

}

void GUI::FilterConfigurationBox::createUi()
{
    filterPreview_=new FrameView;
    filterPreview_->setFixedSize(200,200);
    filterPreview_->setFrame(getDefaultImage());

    label_filter_=new QLabel(tr("Filter options:"));
    QFont font("Sans Serif",14,QFont::Bold);
    label_filter_->setFont(font);

    filterOptionsArea_=new QScrollArea;
    filterOptionsArea_->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    filterOptionsArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

    v_filterOptions_=new QVBoxLayout;

    createFilterOptions();

    QFrame* wrapper=new QFrame;
    wrapper->setLayout(v_filterOptions_);
    filterOptionsArea_->setWidget(wrapper);

   h_content=new QHBoxLayout;

    h_content->addWidget(filterPreview_);
    h_content->addSpacing(20);

    QVBoxLayout* v_caption_options=new QVBoxLayout;
    v_caption_options->addWidget(label_filter_);
    v_caption_options->addSpacing(10);
    v_caption_options->addWidget(filterOptionsArea_);

    h_content->addLayout(v_caption_options);


}

QImage& GUI::FilterConfigurationBox::getDefaultImage() {
    if(defaultImage_.get()) {
        return *defaultImage_;
    }
    defaultImage_=std::make_unique<QImage>(":/pictures/resources/flower_example.png");

    return *defaultImage_;
}
