#include "testgrayscalefilter.h"

#include "../../../src/model/filters/GrayscaleFilter.h"

void TestGrayscaleFilter::init() {
	filter_=Model::GrayscaleFilter();
}

void TestGrayscaleFilter::testGetName() {
	QVERIFY(filter_.getName()==Model::GrayscaleFilter::FILTERNAME);
}

void TestGrayscaleFilter::testGetFilterDescription() {
	QVERIFY(filter_.getFilterDescription()==
	        "colorchannelmixer=',3':',4':',3':0:',3':',4':',3':0:',3':',4':',3'");
}
