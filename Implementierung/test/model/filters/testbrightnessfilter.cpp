#include "testbrightnessfilter.h"

#include "../../../src/model/filters/BrightnessFilter.h"

void TestBrightnessFilter::init() {
	filter_=Model::BrightnessFilter();
}

void TestBrightnessFilter::testSetIntensity() {
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

void TestBrightnessFilter::testRestore() {
	filter_.restore("50");
	QVERIFY(filter_.getIntensity()==50);

	filter_.restore("101");
	QVERIFY(filter_.getIntensity()!=101);

	filter_.restore("-101");
	QVERIFY(filter_.getIntensity()!=-101);
}

void TestBrightnessFilter::testGetSaveString() {
	filter_.setIntensity(60);
	QVERIFY(filter_.getSaveString()=="60");
}

void TestBrightnessFilter::testFilterCopy() {
	const int testValue=100;
	Model::BrightnessFilter filter2;
	filter2.setIntensity(testValue);

	filter_.restore(filter2.getSaveString());
	QVERIFY(filter_.getIntensity()==testValue);
}

void TestBrightnessFilter::testGetFilterDescription() {
	filter_.setIntensity(100);
	QVERIFY(filter_.getFilterDescription()==
            "eq=contrast=1:brightness='1,000000':saturation=1:gamma=1:gamma_r=1:gamma_g=1:gamma_b=1:gamma_weight=1");
}
