#include "testsepiafilter.h"

#include "../../../src/model/filters/SepiaFilter.h"

void TestSepiaFilter::init() {
	filter_=Model::SepiaFilter();
}

void TestSepiaFilter::testGetName() {
	QVERIFY(filter_.getName()==Model::SepiaFilter::FILTERNAME);
}

void TestSepiaFilter::testGetFilterDescription() {
	QVERIFY(filter_.getFilterDescription()==
	        "colorchannelmixer=',393':',769':',189':0:',349':',686':',168':0:',272':',534':',131'");
}
