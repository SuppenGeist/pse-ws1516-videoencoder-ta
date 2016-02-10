#include "filtertestsuite.h"

#include <QtTest>

#include "testblurfilter.h"
#include "testborderfilter.h"
#include "testbrightnessfilter.h"
#include "testcontrastfilter.h"


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

    TestContrastFilter testContrastFilter;
    QTest::qExec(&testContrastFilter);
}

