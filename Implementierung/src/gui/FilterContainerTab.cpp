#include "FilterContainerTab.h"

#include <vector>

#include <QFrame>
#include <QWidget>
#include <QHBoxLayout>

#include "FilterView.h"
#include "FilterTab.h"

GUI::FilterContainerTab::FilterContainerTab(QWidget* parent):QFrame(parent) {
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    createUi();
}

void GUI::FilterContainerTab::addFilter(QString filtername) {
    FilterView *view = new FilterView;
    view->setFilter(filtername);
    view->setFilterTab(*parentTab_);
    container_->addWidget(view);
}

void GUI::FilterContainerTab::setParentTab(FilterTab& parent) {
    parentTab_=&parent;
}

void GUI::FilterContainerTab::createUi()
{
    container_=new QHBoxLayout;
    setLayout(container_);
}
