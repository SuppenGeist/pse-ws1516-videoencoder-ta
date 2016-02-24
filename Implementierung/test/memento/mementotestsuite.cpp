#include "mementotestsuite.h"
#include "testanalysisboxcontainermemento.h"
#include "testanalysisboxmemento.h"
#include "testanalysistabmemento.h"
#include "testfiltertabmemento.h"
#include "testmainwindowmemento.h"

MementoTestSuite::MementoTestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void MementoTestSuite::testMemento() {
	TestAnalysisBoxContainerMemento testAnalysisBoxContainerMemento;
	QTest::qExec(&testAnalysisBoxContainerMemento);

	TestAnalysisBoxMemento testAnalysisBoxMemento;
	QTest::qExec(&testAnalysisBoxMemento);

	TestAnalysisTabMemento testAnalysisTabMemento;
	QTest::qExec(&testAnalysisTabMemento);

	TestFilterTabMemento testFilterTabMemento;
	QTest::qExec(&testFilterTabMemento);

	TestMainWindowMemento testMainWindowMemento;
	QTest::qExec(&testMainWindowMemento);

}
