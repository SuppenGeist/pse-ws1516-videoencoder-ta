#include "testsaturationfilter.h"

#include "../../../src/model/filters/SaturationFilter.h"

void TestSaturationFilter::init() {
	filter_=Model::SaturationFilter();
}

void TestSaturationFilter::testSetIntensity() {
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

void TestSaturationFilter::testRestore() {
	filter_.restore("60");
	QVERIFY(filter_.getIntensity()==60);

	filter_.restore("102");
	QVERIFY(filter_.getIntensity()!=102);

	filter_.restore("-1");
	QVERIFY(filter_.getIntensity()!=-1);
}

void TestSaturationFilter::testGetSaveString() {
	filter_.setIntensity(60);
	QVERIFY(filter_.getSaveString()=="60");
}

void TestSaturationFilter::testFilterCopy() {
	const int testValue=100;
	Model::SaturationFilter filter2;
	filter2.setIntensity(testValue);

	filter_.restore(filter2.getSaveString());
	QVERIFY(filter_.getIntensity()==testValue);
}

void TestSaturationFilter::testGetFilterdescrition() {
	filter_.setIntensity(66);
	QVERIFY(filter_.getFilterDescription()==
	        "eq=contrast=1:brightness=0:saturation='2.000000':gamma=1:gamma_r=1:gamma_g=1:gamma_b=1:gamma_weight=1");

}
