#include "guitestsuite.h"

#include "testmainwindow.h"

GUITestSuite::GUITestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void GUITestSuite::testGUI() {
    TestMainWindow testMainWindow;
    QTest::qExec(&testMainWindow);

}
