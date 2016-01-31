#include "FilterContainerTab.h"

#include <exception>
#include <string>
#include <vector>
//#include <QWidget.h>

#include "FilterTab.h"
#include "FilterView.h"
#include "../model/filters/Filter.h"
#include "ui_filtercontainertab.h"

GUI::FilterContainerTab::FilterContainerTab(QWidget* parent):QFrame(parent) {
    ui = new Ui::FilterContainerTab;
    ui->setupUi(this);


}

void GUI::FilterContainerTab::addFilter(Model::Filter* filter) {
    FilterView *v = new FilterView(this);
    ui->container->addWidget(v);
    v->setFilter(filter);
    v->setFilterTab(parentTab);
    int b = size().width();
    resize(215+b, 200);
}

void GUI::FilterContainerTab::setParentTab(FilterTab& parent) {
	throw "Not yet implemented";
}

void GUI::FilterContainerTab::uncheck(string filterName) {
	throw "Not yet implemented";
}

