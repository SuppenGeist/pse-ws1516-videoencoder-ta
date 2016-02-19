#include "testsharpnessfilter.h"

#include "../../../src/model/filters/SharpnessFilter.h"

void TestSharpnessFilter::init()
{
    filter_=Model::SharpnessFilter();
}

void TestSharpnessFilter::testSetIntensity()
{
    const int testValue1=0;
    filter_.setIntensity(testValue1);
    QVERIFY(testValue1 == filter_.getIntensity());

    const int testValue2=100;
    filter_.setIntensity(testValue2);
    QVERIFY(testValue2 == filter_.getIntensity());

    const int testValue3=101;
    filter_.setIntensity(testValue3);
    QVERIFY(testValue3 != filter_.getIntensity());

    const int testValue4=-101;
    filter_.setIntensity(testValue4);
    QVERIFY(testValue4 != filter_.getIntensity());
}

void TestSharpnessFilter::testRestore()
{
    filter_.restore("60");
    QVERIFY(filter_.getIntensity()==60);

    filter_.restore("102");
    QVERIFY(filter_.getIntensity()!=102);

    filter_.restore("-102");
    QVERIFY(filter_.getIntensity()!=-1);
}

void TestSharpnessFilter::testGetSaveString()
{
    filter_.setIntensity(60);
    QVERIFY(filter_.getSaveString()=="60");
}

void TestSharpnessFilter::testFilterCopy()
{
    const int testValue=100;
    Model::SharpnessFilter filter2;
    filter2.setIntensity(testValue);

    filter_.restore(filter2.getSaveString());
    QVERIFY(filter_.getIntensity()==testValue);
}

void TestSharpnessFilter::testGetFilterdescrition(){
    filter_.setIntensity(100);
    QVERIFY(filter_.getFilterDescription()=="unsharp=la=5");

}

