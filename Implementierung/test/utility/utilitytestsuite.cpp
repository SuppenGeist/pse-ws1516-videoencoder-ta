#include "utilitytestsuite.h"

#include <QtTest/QtTest>

#include "testvideoconverter.h"
#include "testvideoloader.h"
#include "testyuv444filereader.h"
#include "testyuv422filereader.h"
#include "testyuv411filereader.h"
#include "testyuvfilereader.h"
#include "testyuv411vector.h"
#include "testyuv422vector.h"
#include "testyuv444vector.h"
#include "filterconfigurationtest.h"

UtilityTestSuite::UtilityTestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void UtilityTestSuite::testUtility() {
    //FilterConfigurationTest filterConfigurationTest;
    //QTest::qExec(&filterConfigurationTest);

    TestVideoConverter testVideoConverter;
    QTest::qExec(&testVideoConverter);

    //TestVideoLoader testVideoLoader;
    //QTest::qExec(&testVideoLoader);

    TestYuv444FileReader testYuv444FileReader;
    QTest::qExec(&testYuv444FileReader);

    TestYuv422FileReader testYuv422FileReader;
    QTest::qExec(&testYuv422FileReader);

    TestYuv411FileReader testYuv411FileReader;
    QTest::qExec(&testYuv411FileReader);

    TestYuvFileReader testYuvFileReader;
    QTest::qExec(&testYuvFileReader);

    TestYuv444Vector testYuv444Vector;
    QTest::qExec(&testYuv444Vector);

    TestYuv422Vector testYuv422Vector;
    QTest::qExec(&testYuv422Vector);

    TestYuv411Vector testYuv411Vector;
    QTest::qExec(&testYuv411Vector);


}
