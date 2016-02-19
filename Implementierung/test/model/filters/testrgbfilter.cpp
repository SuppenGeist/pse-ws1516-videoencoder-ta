#include "testrgbfilter.h"

#include "../../../src/model/filters/RGBFilter.h"

void TestRGBFilter::init() {
	filter_=Model::RGBFilter();
}

void TestRGBFilter::testRestore() {
	filter_.restore("0");
	QVERIFY(filter_.getColor()==Model::BasicColor::RED);

	filter_.restore("1");
	QVERIFY(filter_.getColor()==Model::BasicColor::GREEN);

	filter_.restore("2");
	QVERIFY(filter_.getColor()==Model::BasicColor::BLUE);
}

void TestRGBFilter::testGetSaveString() {
	filter_.setColor(Model::BasicColor::GREEN);
	QVERIFY(filter_.getSaveString()=="1");
}

void TestRGBFilter::testFilterCopy() {
	Model::RGBFilter filter2;
	filter2.setColor(Model::BasicColor::BLUE);

	filter_.restore(filter2.getSaveString());
	QVERIFY(filter_.getColor()==Model::BasicColor::BLUE);
}

void TestRGBFilter::testGetFilterDescription() {
	filter_.setColor(Model::BasicColor::GREEN);
	QVERIFY(filter_.getFilterDescription()=="colorchannelmixer=0:0:0:0:0:1:0:0:0:0:0:0");

}
