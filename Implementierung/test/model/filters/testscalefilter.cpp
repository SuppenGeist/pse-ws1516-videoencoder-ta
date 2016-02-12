#include "testscalefilter.h"

#include "../../../src/model/filters/ScaleFilter.h"
#include <QColor>

void TestScaleFilter::init()
{
    filter_=Model::ScaleFilter();
}

void TestScaleFilter::testRestore()
{
    filter_.restore("50;60;1;4");
    QVERIFY(filter_.getWidth()==50);
    QVERIFY(filter_.getHeight()==60);
    QVERIFY(filter_.getKeepRatio()==true);
    QVERIFY(filter_.getRatio()==4);
}

void TestScaleFilter::testFilterCopy()
{
    const int testValue=3;
    const int testValue2=150;
    const bool testValue3=true;
    Model::ScaleFilter filter2;
    filter2.setHeight(testValue2);
    filter2.setWidth(testValue2);
    filter2.setRatio(testValue);
    filter2.setKeepRatio(testValue3);

    filter_.restore(filter2.getSaveString());
    QVERIFY(filter_.getHeight()==testValue2);
    QVERIFY(filter_.getWidth()==testValue2);
    QVERIFY(filter_.getRatio()==testValue);
    QVERIFY(filter_.getKeepRatio()==testValue3);
}

void TestScaleFilter::testGetFilterDescription(){
    filter_.setHeight(110);
    filter_.setWidth(120);
    filter_.setRatio(4);
    filter_.setKeepRatio(true);
    QVERIFY(filter_.getFilterDescription()=="scale=4*iw:4*ih");
}

