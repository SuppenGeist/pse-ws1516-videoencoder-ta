#include "utilitytestsuite.h"

#include <QtTest/QtTest>

#include "testvideoconverter.h"

UtilityTestSuite::UtilityTestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void UtilityTestSuite::testUtility() {
    TestVideoConverter testVideoConverter;
    QTest::qExec(&testVideoConverter);
}
