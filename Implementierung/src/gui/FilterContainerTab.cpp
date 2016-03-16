#include "FilterContainerTab.h"

#include <vector>

#include <QFrame>
#include <QWidget>
#include <QHBoxLayout>
#include <QSpacerItem>

#include "FilterView.h"
#include "FilterTab.h"

GUI::FilterContainerTab::FilterContainerTab(QWidget* parent):QFrame(parent) {
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	createUi();
}

void GUI::FilterContainerTab::addFilter(QString filtername) {
	FilterView *view = new FilterView;
	view->setFilter(filtername);
	view->setFilterTab(parentTab_);
	filterContainer_->addWidget(view);
	filterViews_.push_back(view);
}

void GUI::FilterContainerTab::setParentTab(FilterTab& parent) {
	parentTab_=&parent;
}

void GUI::FilterContainerTab::createUi() {
	container_=new QHBoxLayout;
	filterContainer_=new QHBoxLayout;
	container_->addLayout(filterContainer_);
	QSpacerItem* sp=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	container_->addSpacerItem(sp);
	setLayout(container_);
}
