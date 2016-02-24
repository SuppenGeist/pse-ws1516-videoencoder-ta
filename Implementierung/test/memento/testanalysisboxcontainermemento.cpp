#include "testanalysisboxcontainermemento.h"

void TestAnalysisBoxContainerMemento::init() {

	memento_ = Memento::AnalysisBoxContainerMemento();
}

void TestAnalysisBoxContainerMemento::testAddMemento() {
	std::unique_ptr<Memento::AnalysisBoxMemento> box(new Memento::AnalysisBoxMemento);

	QVERIFY(memento_.getAnalysisBoxList().size()==0);

	memento_.addMemento(std::move(box));
	QVERIFY(memento_.getAnalysisBoxList().size()!= 0);

}

