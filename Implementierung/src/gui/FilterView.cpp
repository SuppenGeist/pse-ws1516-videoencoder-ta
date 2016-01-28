#include <exception>

#include "FilterView.h"
#include "FilterTab.h"
#include "QWidget.h"
#include "Filter.h"

GUI::FilterView::FilterView(QWidget* parent) {
}

void GUI::FilterView::checkBoxStateChanged(int state) {
	throw "Not yet implemented";
}

/*
 * void GUI::FilterView::setFilter(Filter filter) {
	throw "Not yet implemented";
}
*/

void GUI::FilterView::setFilterTab(FilterTab* filtertab) {
	this->filterTab = filtertab;
}


