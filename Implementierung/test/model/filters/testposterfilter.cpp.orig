#include "testposterfilter.h"

#include "../../../src/model/filters/PosterFilter.h"

void TestPosterFilter::init()
{
    filter_=Model::PosterFilter();
}

void TestPosterFilter::testSetNumberOfColors()
{
    const int testValue1=0;
    filter_.setNumberOfColors(testValue1);
    QVERIFY(testValue1 == filter_.getNumberOfColors());

    const int testValue2=16777216;
    filter_.setNumberOfColors(testValue2);
    QVERIFY(testValue2 == filter_.getNumberOfColors());

    const int testValue3=16777217;
    filter_.setNumberOfColors(testValue3);
    QVERIFY(testValue3 != filter_.getNumberOfColors());

    const int testValue4=-1;
    filter_.setNumberOfColors(testValue4);
    QVERIFY(testValue4 != filter_.getNumberOfColors());
}

void TestPosterFilter::testRestore()
{
    filter_.restore("60");
    QVERIFY(filter_.getNumberOfColors()==60);

    filter_.restore("16777217");
    QVERIFY(filter_.getNumberOfColors()!=16777217);

    filter_.restore("-1");
    QVERIFY(filter_.getNumberOfColors()!=-1);
}

void TestPosterFilter::testGetSaveString()
{
    filter_.setNumberOfColors(60);
    QVERIFY(filter_.getSaveString()=="60");
}

void TestPosterFilter::testFilterCopy()
{
    const int testValue=100;
    Model::PosterFilter filter2;
    filter2.setNumberOfColors(testValue);

    filter_.restore(filter2.getSaveString());
    QVERIFY(filter_.getNumberOfColors()==testValue);
}
