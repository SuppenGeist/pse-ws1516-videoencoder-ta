#include "MainWindowMemento.h"

#include "AnalysisTabMemento.h"
#include "FilterTabMemento.h"

Memento::MainWindowMemento::MainWindowMemento():selectedTab_(0) {
}

int Memento::MainWindowMemento::getSelectedTab() {
    return selectedTab_;
}

void Memento::MainWindowMemento::setSelectedTab(int selectedTab) {
    selectedTab_ = selectedTab;
}

Memento::AnalysisTabMemento* Memento::MainWindowMemento::getAnalysisTabMemento() {
    return analysisTab_.get();
}

void Memento::MainWindowMemento::setAnalysisTabMemento(std::unique_ptr<AnalysisTabMemento> analysisTabMemento) {
    analysisTab_ = std::move(analysisTabMemento);
}

Memento::FilterTabMemento* Memento::MainWindowMemento::getFilterTabMemento() {
    return filterTab_.get();
}

void Memento::MainWindowMemento::setFilterTabMemento(std::unique_ptr<FilterTabMemento> filterTabMemento) {
    filterTab_ = std::move(filterTabMemento);
}
