#include "FilterView.h"

#include <memory>

#include <QWidget>
#include <QImage>
#include <QFrame>
#include <QSize>
#include <QVBoxLayout>
#include <QPushButton>
#include <QImage>
#include <QDebug>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include "FilterTab.h"
#include "../model/filters/Filter.h"
#include "FrameView.h"
#include "../utility/VideoConverter.h"
#include "../utility/FilterApplier.h"
#include "../model/FilterList.h"

std::unique_ptr<QImage> GUI::FilterView::defaultImage_;


GUI::FilterView::FilterView(QWidget* parent):QFrame(parent) {
    setFixedWidth(171);
    setFixedHeight(210);

    createUi();
}

GUI::FilterView::~FilterView()
{
    filterView_->clear();
}


void GUI::FilterView::buttonPressed() {

}

void GUI::FilterView::setFilter(QString filtername) {
    filter_=Model::Filter::CreateFilter(filtername);
    button_addFilter_->setText("Add "+filter_->getName()+" filter");

    Model::FilterList filterList;
    filterList.appendFilter(filtername);

    auto avframe=Utility::VideoConverter::convertQImageToAVFrame(getDefaultImage());

    Utility::FilterApplier applier(filterList,avframe->width,avframe->height,avframe->format);

    auto filteredFrame=applier.applyToFrame(*avframe);

    filterImage_=Utility::VideoConverter::convertAVFrameToQImage(*filteredFrame);
    filterView_->setFrame(*filterImage_);

    av_frame_free(&avframe);
    av_frame_free(&filteredFrame);
}

QImage& GUI::FilterView::getDefaultImage() {
    if(defaultImage_.get()) {
        return *defaultImage_;
    }
    defaultImage_=std::make_unique<QImage>(":/pictures/resources/flower_example.png");

    return *defaultImage_;
}

void GUI::FilterView::createUi() {
    filterView_=new FrameView;
    filterView_->setFixedSize(QSize(150,150));

    filterView_->setFrame(getDefaultImage());

    QString stylesheet("QPushButton {"
                                   "color: rgb(0, 0, 0);"
                                   "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c);"
                                   "background: rgb(220, 220, 220);"
                                   "border-width: 1px;"
                                   "border-color:rgb(0, 0, 0);"
                                   "border-style: outset;"
                                   "border-radius: 7;"
                                   "font-size: 12px;"
                                   "}"
                                   "QPushButton:pressed {"
                                   "background-color: rgb(200, 200, 200);"
                                   "border-style: inset;"
                                   "}"
                                  );

    button_addFilter_=new QPushButton;
    button_addFilter_->setFixedSize(QSize(150,30));
    button_addFilter_->setFlat(true);
    button_addFilter_->setStyleSheet(stylesheet);

    QVBoxLayout* v_content=new QVBoxLayout;
    v_content->addWidget(filterView_);
    v_content->addWidget(button_addFilter_);

    setLayout(v_content);
    setStyleSheet("QFrame {"
                  "background-color:rgb(245,245,245);"
                  "border-width:2px;"
                  "border-color:rgb(0,0,0);"
                  "border-style: outset;"
                  "}");
}

void GUI::FilterView::setFilterTab(FilterTab& filtertab) {
    filterTab_=&filtertab;
}

