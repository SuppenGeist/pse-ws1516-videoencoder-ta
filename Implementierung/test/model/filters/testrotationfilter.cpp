#include "testrotationfilter.h"

#include "../../../src/model/filters/RotationFilter.h"

void TestRotationFilter::init()
{
    filter_=Model::RotationFilter();
}

void TestRotationFilter::testSetAngle()
{
    const int testValue1=0;
    filter_.setAngle(testValue1);
    QVERIFY(testValue1 == filter_.getAngle());

    const int testValue2=100;
    filter_.setAngle(testValue2);
    QVERIFY(testValue2 == filter_.getAngle());

    const int testValue3=500;
    filter_.setAngle(testValue3);
    QVERIFY(testValue3 == filter_.getAngle());

    const int testValue4=-100;
    filter_.setAngle(testValue4);
    QVERIFY(testValue4 == filter_.getAngle());
}

void TestRotationFilter::testRestore()
{
    filter_.restore("60");
    QVERIFY(filter_.getAngle()==60);

    filter_.restore("102");
    QVERIFY(filter_.getAngle()==102);

    filter_.restore("-1");
    QVERIFY(filter_.getAngle()==-1);
}

void TestRotationFilter::testGetSaveString()
{
    filter_.setAngle(60);
    QVERIFY(filter_.getSaveString()=="60");
}

void TestRotationFilter::testGetFilterDescrition(){
    filter_.setAngle(100);
    QVERIFY(filter_.getFilterDescription()=="rotate=100*PI/180");

}

void TestRotationFilter::testFilterCopy()
{
    const int testValue=100;
    Model::RotationFilter filter2;
    filter2.setAngle(testValue);

    filter_.restore(filter2.getSaveString());
    QVERIFY(filter_.getAngle()==testValue);
}
