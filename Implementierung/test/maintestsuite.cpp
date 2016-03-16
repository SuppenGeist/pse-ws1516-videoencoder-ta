#include "maintestsuite.h"

#include "model/modeltestsuite.h"
#include "gui/guitestsuite.h"
#include "memento/mementotestsuite.h"
#include "utility/utilitytestsuite.h"

MainTestSuit::MainTestSuit(int argc,char* argv[]):argc_(argc),argv_(argv) {

}

void MainTestSuit::runAllTests() {
	ModelTestSuite modelTestSuite(argc_,argv_);
	GUITestSuite guiTestSuite(argc_,argv_);
	MementoTestSuite mementotestsuite(argc_,argv_);
	UtilityTestSuite utilitytestsuite(argc_,argv_);
	modelTestSuite.testModel();
	mementotestsuite.testMemento();
	utilitytestsuite.testUtility();
	guiTestSuite.testGUI();
}

