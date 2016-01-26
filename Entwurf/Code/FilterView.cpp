#include <exception>

#include "FilterView.h"
#include "FilterTab.h"
#include "QWidget.h"
#include "Filter.h"

FilterView::FilterView(QWidget* parent) {
}

void FilterView::checkBoxStateChanged(int state) {
	throw "Not yet implemented";
}

void FilterView::setFilter(Filter filter) {
	throw "Not yet implemented";
}

void FilterView::setFilterTab(FilterTab* filtertab) {
	this->filterTab = filtertab;
}


