#include "FilterView.h"

#include <memory>

#include <QWidget>
#include <QImage>
#include <QFrame>


#include "FilterTab.h"
#include "../model/filters/Filter.h"

std::unique_ptr<QImage> GUI::FilterView::defaultImage_;


GUI::FilterView::FilterView(QWidget* parent):QFrame(parent) {
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    createUi();
}


void GUI::FilterView::buttonPressed() {

}

void GUI::FilterView::setFilter(QString filtername) {
    filter_=Model::Filter::createFilter(filtername);
}

QImage& GUI::FilterView::getDefaultImage() {

}

void GUI::FilterView::createUi() {

}

void GUI::FilterView::setFilterTab(FilterTab& filtertab) {
    filterTab_=&filtertab;
}

