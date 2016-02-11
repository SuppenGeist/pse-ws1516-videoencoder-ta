#include "testedgefilter.h"

#include "../../../src/model/filters/EdgeFilter.h"

void TestEdgeFilter::init()
{
    filter_=Model::EdgeFilter();
}

void TestEdgeFilter::testGetName()
{
    QVERIFY(filter_.getName()==Model::EdgeFilter::FILTERNAME);
}

void TestEdgeFilter::testGetFilterDescription(){
    QVERIFY(filter_.getFilterDescription()=="edgedetect");
}
