#include "testcolorbalancefilter.h"

#include "../../../src/model/filters/ColorbalanceFilter.h"
#include "../../../src/utility/BasicColor.h"

void TestColorbalanceFilter::init() {
	filter_=Model::ColorbalanceFilter();
}

void TestColorbalanceFilter::testSetIntensity() {
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

void TestColorbalanceFilter::testRestore() {
	filter_.restore("50;0;0;0;2");
	QVERIFY(filter_.getIntensity()==50);
	QVERIFY(!filter_.getBrightPixels());
	QVERIFY(!filter_.getMediumPixels());
	QVERIFY(!filter_.getDarkPixels());
	QVERIFY(filter_.getColor()==Model::BasicColor::BLUE);

}

void TestColorbalanceFilter::testGetSaveString() {
	filter_.setIntensity(60);
	filter_.setBrightPixels(false);
	filter_.setDarkPixels(false);
	filter_.setMediumPixels(false);
	filter_.setColor(Model::BasicColor::GREEN);
	QVERIFY(filter_.getSaveString()=="60;0;0;0;1");
}

void TestColorbalanceFilter::testFilterCopy() {
	const int testValue=100;
	const int testValue2=1;
	Model::ColorbalanceFilter filter2;
	filter2.setIntensity(testValue);
	filter2.setColor(Model::BasicColor::GREEN);
	filter2.setBrightPixels(testValue2);
	filter2.setMediumPixels(testValue2);
	filter2.setDarkPixels(testValue2);

	filter_.restore(filter2.getSaveString());
	QVERIFY(filter_.getIntensity()==testValue);
	QVERIFY(filter_.getBrightPixels()==testValue2);
	QVERIFY(filter_.getMediumPixels()==testValue2);
	QVERIFY(filter_.getDarkPixels()==testValue2);
	QVERIFY(filter_.getColor()==1);
}

void TestColorbalanceFilter::testGetFilterDescription() {
	filter_.setIntensity(100);
	filter_.setBrightPixels(false);
	filter_.setDarkPixels(true);
	filter_.setMediumPixels(false);
	filter_.setColor(Model::BasicColor::GREEN);
	QVERIFY(filter_.getFilterDescription()=="colorbalance=gs='1,000000':");
}
