#include <exception>

#include "MainWindowMemento.h"
#include "AnalysisTabMemento.h"
#include "FilterTabMemento.h"

MainWindowMemento::MainWindowMemento() {
}

int MainWindowMemento::getSelectedTab() {
	return this->selectedTab;
}

void MainWindowMemento::setSelectedTab(int selectedTab) {
	this->selectedTab = selectedTab;
}

Memento::AnalysisTabMemento MainWindowMemento::getAnalysisTabMemento() {
	throw "Not yet implemented";
}

void MainWindowMemento::setAnalysisTabMemento(AnalysisTabMemento analysisTabMeMento) {
	throw "Not yet implemented";
}

Memento::FilterTabMemento MainWindowMemento::getFilterTabMemento() {
	throw "Not yet implemented";
}

void MainWindowMemento::setFilterTabMemento(FilterTabMemento filterTabMemento) {
	throw "Not yet implemented";
}

