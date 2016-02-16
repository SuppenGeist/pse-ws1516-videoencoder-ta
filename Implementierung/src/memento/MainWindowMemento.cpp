#include "MainWindowMemento.h"

#include "AnalysisTabMemento.h"
#include "FilterTabMemento.h"

Memento::MainWindowMemento::MainWindowMemento() {
}

int Memento::MainWindowMemento::getSelectedTab() {
    return selectedTab_;
}

void Memento::MainWindowMemento::setSelectedTab(int selectedTab) {
    selectedTab_ = selectedTab;
}

Memento::AnalysisTabMemento* Memento::MainWindowMemento::getAnalysisTabMemento() {
    return analysisTab_;
}

void Memento::MainWindowMemento::setAnalysisTabMemento(AnalysisTabMemento* analysisTabMemento) {
    analysisTab_ = analysisTabMemento;
}

Memento::FilterTabMemento* Memento::MainWindowMemento::getFilterTabMemento() {
    return filterTab_;
}

void Memento::MainWindowMemento::setFilterTabMemento(FilterTabMemento* filterTabMemento) {
    filterTab_ = filterTabMemento;
}
