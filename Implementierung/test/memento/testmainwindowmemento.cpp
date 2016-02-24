#include "testmainwindowmemento.h"

void TestMainWindowMemento::init() {

	memento_ = Memento::MainWindowMemento();

}

void TestMainWindowMemento::testSetAnalysisTab() {
	std::unique_ptr<Memento::AnalysisTabMemento> tab(new Memento::AnalysisTabMemento());
	QVERIFY(memento_.getAnalysisTabMemento() == nullptr);
	memento_.setAnalysisTabMemento(std::move(tab));
	QVERIFY(memento_.getAnalysisTabMemento() != nullptr);
}

void TestMainWindowMemento::testSetFilterTab() {
	std::unique_ptr<Memento::FilterTabMemento> tab(new Memento::FilterTabMemento());
	QVERIFY(memento_.getFilterTabMemento() == nullptr);
	memento_.setFilterTabMemento(std::move(tab));
	QVERIFY(memento_.getFilterTabMemento() != nullptr);

}

void TestMainWindowMemento::testSetSelectedTab() {
	int value = 1;
	memento_.setSelectedTab(value);
	QVERIFY(memento_.getSelectedTab() == value);

}
