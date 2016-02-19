#include "testgridfilter.h"

#include "../../../src/model/filters/GridFilter.h"
#include <QColor>

void TestGridFilter::init() {
	filter_=Model::GridFilter();
}

void TestGridFilter::testSetOpacity() {
	const int testValue1=0;
	filter_.setOpacity(testValue1);
	QVERIFY(testValue1 == filter_.getOpacity());

	const int testValue2=255;
	filter_.setOpacity(testValue2);
	QVERIFY(testValue2 == filter_.getOpacity());

	const int testValue3=-1;
	filter_.setOpacity(testValue3);
	QVERIFY(testValue3 != filter_.getOpacity());

	const int testValue4=-256;
	filter_.setOpacity(testValue4);
	QVERIFY(testValue4 != filter_.getOpacity());
}

void TestGridFilter::testRestore() {
	filter_.restore("3;4;2;240;#FF00AB");
	QVERIFY(filter_.getHorizontalCells()==3);
	QVERIFY(filter_.getVerticalCells()==4);
	QVERIFY(filter_.getThickness()==2);
	QVERIFY(filter_.getOpacity()==240);

	auto color = filter_.getColor();
	QVERIFY(color.red()==255);
	QVERIFY(color.green()==0);
	QVERIFY(color.blue()==171);

}

void TestGridFilter::testFilterCopy() {
	const int testValue=10;
	const int testValue2=5;
	const QColor color("#FFFFFF");

	Model::GridFilter filter2;
	filter2.setOpacity(testValue);
	filter2.setHorizontalCells(testValue2);
	filter2.setVerticalCells(testValue);
	filter2.setThickness(testValue2);
	filter2.setColor(color);

	filter_.restore(filter2.getSaveString());
	QVERIFY(filter_.getOpacity()==testValue);
	QVERIFY(filter_.getHorizontalCells()==testValue2);
	QVERIFY(filter_.getVerticalCells()==testValue);
	QVERIFY(filter_.getThickness()==testValue2);
	QVERIFY(filter_.getColor().name()==color.name());
}

void TestGridFilter::testGetFilterDescription() {
	filter_.setOpacity(100);
	filter_.setHorizontalCells(4);
	filter_.setVerticalCells(3);
	filter_.setThickness(2);
	filter_.setColor(QColor("#FFFFFF"));

	QVERIFY(filter_.getFilterDescription()=="drawgrid=w=iw/4:h=ih/3:t=2:c=#ffffff@0x64");
}
