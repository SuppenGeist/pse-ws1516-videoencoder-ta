#include "AnalysisBoxContainerMemento.h"

#include <vector>
#include "AnalysisBoxMemento.h"

void Memento::AnalysisBoxContainerMemento::analysisBoxMemento() {

}

vector<Memento::AnalysisBoxMemento*> Memento::AnalysisBoxContainerMemento::getAnalysisBoxList() {
    return mementoList_;
}

void Memento::AnalysisBoxContainerMemento::setAnalysisBoxList(
    std::vector<Memento::AnalysisBoxMemento*> analysisBoxList) {
    mementoList_=analysisBoxList;
}
