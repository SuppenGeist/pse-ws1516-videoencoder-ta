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
#include "testfilterconfiguration.h"
#include "testbitratecalculator.h"
#include "testrgbhistogramcalculator.h"
#include "testyuvfilesaver.h"
#include "testyuv444filesaver.h"
#include "testyuv422filesaver.h"
#include "testyuv411filesaver.h"


UtilityTestSuite::UtilityTestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void UtilityTestSuite::testUtility() {
	TestFilterConfiguration testFilterConfiguration;
	QTest::qExec(&testFilterConfiguration);

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

	TestYuvFileReader testYuvFileReader;
	QTest::qExec(&testYuvFileReader);

	TestYuv444Vector testYuv444Vector;
	QTest::qExec(&testYuv444Vector);

	TestYuv422Vector testYuv422Vector;
	QTest::qExec(&testYuv422Vector);

	TestYuv411Vector testYuv411Vector;
	QTest::qExec(&testYuv411Vector);

	TestBitrateCalculator testBitrateCalculator;
	QTest::qExec(&testBitrateCalculator);

	TestRGBHistogramCalculator testRGBHistogramCalculator;
	QTest::qExec(&testRGBHistogramCalculator);

	TestYuvFileSaver testYuvFileSaver;
	QTest::qExec(&testYuvFileSaver);

	TestYuv444FileSaver testYuv444FileSaver;
	QTest::qExec(&testYuv444FileSaver);

	TestYuv422FileSaver testYuv422FileSaver;
	QTest::qExec(&testYuv422FileSaver);

	TestYuv411FileSaver testYuv411FileSaver;
	QTest::qExec(&testYuv411FileSaver);

}
