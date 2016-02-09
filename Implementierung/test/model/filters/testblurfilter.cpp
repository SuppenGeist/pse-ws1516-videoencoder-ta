#include "testblurfilter.h"

#include "../../../src/model/filters/BlurFilter.h"

void TestBlurFilter::init()
{
    testFilter_=Model::BlurFilter();
}

void TestBlurFilter::testSetIntensity()
{
    const int testValue1=0;
    testFilter_.setIntensity(testValue1);
    QVERIFY(testValue1 == testFilter_.getIntensity());

    const int testValue2=100;
    testFilter_.setIntensity(testValue2);
    QVERIFY(testValue2 == testFilter_.getIntensity());

    const int testValue3=101;
    testFilter_.setIntensity(testValue3);
    QVERIFY(testValue3 != testFilter_.getIntensity());

    const int testValue4=-1;
    testFilter_.setIntensity(testValue4);
    QVERIFY(testValue4 != testFilter_.getIntensity());
}

void TestBlurFilter::testRestore()
{
    testFilter_.restore("60");
    QVERIFY(testFilter_.getIntensity()==60);

    testFilter_.restore("102");
    QVERIFY(testFilter_.getIntensity()!=102);

    testFilter_.restore("-1");
    QVERIFY(testFilter_.getIntensity()!=-1);
}

void TestBlurFilter::testGetSaveString()
{
    testFilter_.setIntensity(60);
    QVERIFY(testFilter_.getSaveString()=="60");
}
