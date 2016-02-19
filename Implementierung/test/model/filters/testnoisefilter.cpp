#include "testnoisefilter.h"

#include "../../../src/model/filters/NoiseFilter.h"

void TestNoiseFilter::init() {
	filter_=Model::NoiseFilter();
}

void TestNoiseFilter::testSetIntensity() {
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

void TestNoiseFilter::testRestore() {
	filter_.restore("50;random");
	QVERIFY(filter_.getIntensity()==50);
	QVERIFY(filter_.getMode()==Model::NoiseMode::RANDOM);

	filter_.restore("60;muster");
	QVERIFY(filter_.getIntensity()==60);
	QVERIFY(filter_.getMode()==Model::NoiseMode::MUSTER);

}


void TestNoiseFilter::testGetDescription() {
	filter_.setIntensity(60);
	filter_.setMode(Model::NoiseMode::RANDOM);
	QVERIFY(filter_.getFilterDescription()=="noise=alls='60':allf=t+p");
}

void TestNoiseFilter::testFilterCopy() {
	const int testValue=100;
	Model::NoiseFilter filter2;
	filter2.setIntensity(testValue);
	filter2.setMode(Model::NoiseMode::STATIC);

	filter_.restore(filter2.getSaveString());
	QVERIFY(filter_.getIntensity()==testValue);
	QVERIFY(filter_.getMode()==Model::NoiseMode::STATIC);
}
