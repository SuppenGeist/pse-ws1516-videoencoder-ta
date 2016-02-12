#include "filtertestsuite.h"

#include <QtTest>

#include "testblurfilter.h"
#include "testborderfilter.h"
#include "testbrightnessfilter.h"
#include "testcolorbalancefilter.h"
#include "testcontrastfilter.h"
#include "testedgefilter.h"
#include "testgrayscalefilter.h"
#include "testgridfilter.h"
#include "testmirrorfilter.h"
#include "testnegativefilter.h"
#include "testnoisefilter.h"
#include "testposterfilter.h"
#include "testrectanglefilter.h"
#include "testrgbfilter.h"
#include "testrotationfilter.h"
#include "testsaturationfilter.h"
#include "testscalefilter.h"
#include "testsepiafilter.h"
#include "testsharpnessfilter.h"
#include "testvintagefilter.h"


FilterTestSuite::FilterTestSuite(int argc,char* argv[]):argc_(argc),argv_(argv)
{

}

void FilterTestSuite::testAllFilters()
{
    TestBlurFilter testBlurFilter;
    QTest::qExec(&testBlurFilter,argc_,argv_);

    TestBorderFilter testBorderFilter;
    QTest::qExec(&testBorderFilter);

    TestBrightnessFilter testBrightnessFilter;
    QTest::qExec(&testBrightnessFilter);

    TestColorbalanceFilter testColorbalanceFilter;
    QTest::qExec(&testColorbalanceFilter);

    TestContrastFilter testContrastFilter;
    QTest::qExec(&testContrastFilter);

    TestEdgeFilter testEdgeFilter;
    QTest::qExec(&testEdgeFilter);

    TestGrayscaleFilter testGrayscaleFilter;
    QTest::qExec(&testGrayscaleFilter);

    TestGridFilter testGridFilter;
    QTest::qExec(&testGridFilter);

    TestMirrorFilter testMirrorFilter;
    QTest::qExec(&testMirrorFilter);

    TestNegativeFilter testNegativeFilter;
    QTest::qExec(&testNegativeFilter);

    TestNoiseFilter testNoiseFilter;
    QTest::qExec(&testNoiseFilter);

    TestPosterFilter testPosterFilter;
    QTest::qExec(&testPosterFilter);

    TestRectangleFilter testRectangleFilter;
    QTest::qExec(&testRectangleFilter);

    TestRGBFilter testRGBFilter;
    QTest::qExec(&testRGBFilter);

    TestRotationFilter testRotationFilter;
    QTest::qExec(&testRotationFilter);

    TestScaleFilter testScaleFilter;
    QTest::qExec(&testScaleFilter);

    TestSepiaFilter testSepiaFilter;
    QTest::qExec(&testSepiaFilter);

}

