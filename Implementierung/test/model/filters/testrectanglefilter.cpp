#include "testrectanglefilter.h"
#include <QColor>
#include "../../../src/model/filters/RectangleFilter.h"

void TestRectangleFilter::init()
{
    filter_=Model::RectangleFilter();
}

void TestRectangleFilter::testSetOpacity()
{
    const int testValue1=0;
    filter_.setOpacity(testValue1);
    QVERIFY(testValue1 == filter_.getOpacity());

    const int testValue2=255;
    filter_.setOpacity(testValue2);
    QVERIFY(testValue2 == filter_.getOpacity());

    const int testValue3=256;
    filter_.setOpacity(testValue3);
    QVERIFY(testValue3 != filter_.getOpacity());

    const int testValue4=-1;
    filter_.setOpacity(testValue4);
    QVERIFY(testValue4 != filter_.getOpacity());
}

void TestRectangleFilter::testRestore()
{
    filter_.restore("1;2;3;4;244;#FFFFFF");
    QVERIFY(filter_.getWidth()==1);
    QVERIFY(filter_.getHeight()==2);
    QVERIFY(filter_.getX()==3);
    QVERIFY(filter_.getY()==4);
    QVERIFY(filter_.getOpacity()==244);

    auto color = filter_.getColor();
    QVERIFY(color.red()==255);
    QVERIFY(color.green()==255);
    QVERIFY(color.blue()==255);

}

void TestRectangleFilter::testGetFilterDescription()
{
    filter_.setOpacity(100);
    filter_.setHeight(5);
    filter_.setWidth(4);
    filter_.setX(3);
    filter_.setY(2);
    filter_.setColor(QColor("#FFFFFF"));

    QVERIFY(filter_.getFilterDescription()=="drawbox=x=3:y=2:w=4:h=5:color=#ffffff@0x64:t=max");
}

void TestRectangleFilter::testFilterCopy()
{
    const int testValue=100;
    const int testValue2=5;
    const int testValue3=3;
    const QColor color("#FFFFFF");

    Model::RectangleFilter filter2;
    filter2.setOpacity(testValue);
    filter2.setHeight(testValue2);
    filter2.setWidth(testValue3);
    filter2.setX(testValue3);
    filter2.setY(testValue2);
    filter2.setColor(color);

    filter_.restore(filter2.getSaveString());
    QVERIFY(filter_.getOpacity()==testValue);
    QVERIFY(filter_.getHeight()==testValue2);
    QVERIFY(filter_.getWidth()==testValue3);
    QVERIFY(filter_.getX()==testValue3);
    QVERIFY(filter_.getY()==testValue2);
    QVERIFY(filter_.getColor().name()==color.name());
}
