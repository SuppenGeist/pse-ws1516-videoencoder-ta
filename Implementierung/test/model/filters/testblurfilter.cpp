#include "testblurfilter.h"

#include "../../../src/model/filters/BlurFilter.h"

void TestBlurFilter::init() {
	filter_=Model::BlurFilter();
}

void TestBlurFilter::testSetIntensity() {
	const int testValue1=0;
	filter_.setIntensity(testValue1);
	QVERIFY(testValue1 == filter_.getIntensity());

	const int testValue2=100;
	filter_.setIntensity(testValue2);
	QVERIFY(testValue2 == filter_.getIntensity());

	const int testValue3=101;
	filter_.setIntensity(testValue3);
	QVERIFY(testValue3 != filter_.getIntensity());

	const int testValue4=-1;
	filter_.setIntensity(testValue4);
	QVERIFY(testValue4 != filter_.getIntensity());
}

void TestBlurFilter::testRestore() {
	filter_.restore("60");
	QVERIFY(filter_.getIntensity()==60);

	filter_.restore("102");
	QVERIFY(filter_.getIntensity()!=102);

	filter_.restore("-1");
	QVERIFY(filter_.getIntensity()!=-1);
}

void TestBlurFilter::testGetSaveString() {
	filter_.setIntensity(60);
	QVERIFY(filter_.getSaveString()=="60");
}

void TestBlurFilter::testFilterCopy() {
	const int testValue=100;
	Model::BlurFilter filter2;
	filter2.setIntensity(testValue);

	filter_.restore(filter2.getSaveString());
	QVERIFY(filter_.getIntensity()==testValue);
}
