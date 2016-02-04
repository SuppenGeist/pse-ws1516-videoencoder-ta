#include "MainWindowMemento.h"

#include "AnalysisTabMemento.h"
#include "FilterTabMemento.h"

Memento::MainWindowMemento::MainWindowMemento() {
}

int Memento::MainWindowMemento::getSelectedTab() {
	return this->selectedTab;
}

void Memento::MainWindowMemento::setSelectedTab(int selectedTab) {
	this->selectedTab = selectedTab;
}

Memento::AnalysisTabMemento Memento::MainWindowMemento::getAnalysisTabMemento() {
	throw "Not yet implemented";
}

void Memento::MainWindowMemento::setAnalysisTabMemento(AnalysisTabMemento analysisTabMeMento) {
	throw "Not yet implemented";
}

Memento::FilterTabMemento Memento::MainWindowMemento::getFilterTabMemento() {
	throw "Not yet implemented";
}

void Memento::MainWindowMemento::setFilterTabMemento(FilterTabMemento* filterTabMemento) {
	throw "Not yet implemented";
}
