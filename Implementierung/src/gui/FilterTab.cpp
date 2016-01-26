#include <exception>
#include <string>
#include <vector>

#include "FilterTab.h"
#include "QFrame.h"
#include "VideoPlayer.h"
#include "PreviewControlPanel.h"
#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "FilterContainerTab.h"
#include "QWidget.h"
#include "FilterTabMemento.h"
#include "FilterList.h"
#include "YuvVideo.h"
#include "Filter.h"
#include "LoadFilterVideo.h"

FilterTab::FilterTab(QWidget* parent) {
}

Memento::FilterTabMemento FilterTab::getMemento() {
	throw "Not yet implemented";
}

void FilterTab::restore(FilterTabMemento memento) {
	throw "Not yet implemented";
}

void FilterTab::connectActions() {
	throw "Not yet implemented";
}

void FilterTab::createUi() {
	throw "Not yet implemented";
}

void FilterTab::up() {
	throw "Not yet implemented";
}

void FilterTab::down() {
	throw "Not yet implemented";
}

void FilterTab::remove() {
	throw "Not yet implemented";
}

void FilterTab::load() {
	throw "Not yet implemented";
}

void FilterTab::apply() {
	throw "Not yet implemented";
}

void FilterTab::saveConf() {
	throw "Not yet implemented";
}

void FilterTab::loadConf() {
	throw "Not yet implemented";
}

void FilterTab::reset() {
	throw "Not yet implemented";
}

void FilterTab::save() {
	throw "Not yet implemented";
}

void FilterTab::insertFilter(Filter filter, int index) {
	throw "Not yet implemented";
}

void FilterTab::listSelectionChanged(QModelIndex index) {
	throw "Not yet implemented";
}

void FilterTab::removeFilter(string filterName) {
	throw "Not yet implemented";
}

void FilterTab::showVideo() {
	throw "Not yet implemented";
}

void FilterTab::showPreview() {
	throw "Not yet implemented";
}

void FilterTab::resetFilters() {
	throw "Not yet implemented";
}

void FilterTab::setFilterList(FilterList list) {
	throw "Not yet implemented";
}

void FilterTab::setRawVideo(YuvVideo video) {
	throw "Not yet implemented";
}

void FilterTab::moveFilter(int old, int new_3) {
	throw "Not yet implemented";
}

