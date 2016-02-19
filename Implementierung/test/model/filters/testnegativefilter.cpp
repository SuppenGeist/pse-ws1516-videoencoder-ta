#include "testnegativefilter.h"

#include "../../../src/model/filters/NegativeFilter.h"

void TestNegativeFilter::init() {
	filter_=Model::NegativeFilter();
}

void TestNegativeFilter::testGetName() {
	QVERIFY(filter_.getName()==Model::NegativeFilter::FILTERNAME);
}

void TestNegativeFilter::testGetFilterDescription() {
	QVERIFY(filter_.getFilterDescription()=="negate");
}

void TestNegativeFilter::testGetSaveString() {
	QVERIFY(filter_.getSaveString()=="");
}
