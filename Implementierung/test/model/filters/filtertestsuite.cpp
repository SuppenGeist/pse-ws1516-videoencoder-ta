#include "filtertestsuite.h"

#include <QtTest>

#include "testblurfilter.h"
#include "testborderfilter.h"

FilterTestSuite::FilterTestSuite(int argc,char* argv[]):argc_(argc),argv_(argv)
{

}

void FilterTestSuite::testAllFilters()
{
    TestBlurFilter testBlurFilter;
    QTest::qExec(&testBlurFilter,argc_,argv_);

    TestBorderFilter testBorderFilter;
    QTest::qExec(&testBorderFilter);
}

