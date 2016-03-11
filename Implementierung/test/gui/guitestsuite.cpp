#include "guitestsuite.h"

#include "testmainwindow.h"
#include "testfiltertab.h"
#include "testanalysistab.h"

GUITestSuite::GUITestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void GUITestSuite::testGUI() {
    TestMainWindow testMainWindow;
    QTest::qExec(&testMainWindow);
    TestFilterTab testFilterTab;
    QTest::qExec(&testFilterTab);
    TestAnalysisTab testAnalysisTab;
    QTest::qExec(&testAnalysisTab);
}
