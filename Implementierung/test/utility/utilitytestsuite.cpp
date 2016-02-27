#include "utilitytestsuite.h"

#include <QtTest/QtTest>

#include "testvideoconverter.h"
#include "testvideoloader.h"
#include "testyuv444filereader.h"
#include "testyuv422filereader.h"
#include "testyuv411filereader.h"

UtilityTestSuite::UtilityTestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void UtilityTestSuite::testUtility() {
    TestVideoConverter testVideoConverter;
    QTest::qExec(&testVideoConverter);

    TestVideoLoader testVideoLoader;
    QTest::qExec(&testVideoLoader);

    TestYuv444FileReader testYuv444FileReader;
    QTest::qExec(&testYuv444FileReader);

    TestYuv422FileReader testYuv422FileReader;
    QTest::qExec(&testYuv422FileReader);

    TestYuv411FileReader testYuv411FileReader;
    QTest::qExec(&testYuv411FileReader);

}
