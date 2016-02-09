#include "testborderfilter.h"

void TestBorderFilter::init()
{
    filter_=Model::BorderFilter();
}

void TestBorderFilter::testSetThickness()
{
    const int testValue1=0;
    filter_.setThickness(testValue1);
    QVERIFY(filter_.getThickness()==testValue1);

    const int testValue2=-1;
    filter_.setThickness(testValue2);
    QVERIFY(filter_.getThickness()!=testValue2);

    const int testValue3=101;
    filter_.setThickness(testValue3);
    QVERIFY(filter_.getThickness()==testValue3);
}

void TestBorderFilter::testRestore()
{
    filter_.restore("0;1;0;1;10;#00FF00");
    QVERIFY(filter_.getTop()==false);
    QVERIFY(filter_.getBottom()==true);
    QVERIFY(filter_.getLeft()==true);
    QVERIFY(filter_.getRight()==false);
    QVERIFY(filter_.getThickness()==10);
    QVERIFY(filter_.getColor().red()==0);
    QVERIFY(filter_.getColor().green()==255);
    QVERIFY(filter_.getColor().blue()==0);
}

void TestBorderFilter::testGetSaveString()
{
    filter_.setTop(false);
    filter_.setBottom(false);
    filter_.setRight(false);
    filter_.setLeft(false);
    filter_.setThickness(2);
    filter_.setColor(QColor(0,255,0));
    QVERIFY(filter_.getSaveString().compare("0;0;0;0;2;#00ff0",Qt::CaseInsensitive));
}

void TestBorderFilter::testFilterCopy()
{
    Model::BorderFilter filter2;
    filter2.setTop(true);
    filter2.setBottom(true);
    filter2.setRight(false);
    filter2.setLeft(false);
    filter2.setThickness(17);
    filter2.setColor(QColor(255,0,0));

    filter_.restore(filter2.getSaveString());
    QVERIFY(filter_.getTop()==true);
    QVERIFY(filter_.getBottom()==true);
    QVERIFY(filter_.getLeft()==false);
    QVERIFY(filter_.getRight()==false);
    QVERIFY(filter_.getThickness()==17);
    QVERIFY(filter_.getColor().red()==255);
    QVERIFY(filter_.getColor().green()==0);
    QVERIFY(filter_.getColor().blue()==0);
}
