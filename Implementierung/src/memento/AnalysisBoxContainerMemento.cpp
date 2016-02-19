#include "AnalysisBoxContainerMemento.h"

#include <memory>
#include <vector>

Memento::AnalysisBoxContainerMemento::AnalysisBoxContainerMemento() {

}

std::vector<std::unique_ptr<Memento::AnalysisBoxMemento> >
&Memento::AnalysisBoxContainerMemento::getAnalysisBoxList() {
	return mementoList_;
}

void Memento::AnalysisBoxContainerMemento::addMemento(std::unique_ptr<Memento::AnalysisBoxMemento>
        memento) {
	mementoList_.push_back(std::move(memento));
}
