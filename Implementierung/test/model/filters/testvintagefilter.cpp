#include "testvintagefilter.h"

#include "../../../src/model/filters/VintageFilter.h"

void TestVintageFilter::init()
{
    filter_=Model::VintageFilter();
}

void TestVintageFilter::testGetName()
{
    QVERIFY(filter_.getName()==Model::VintageFilter::FILTERNAME);
}

void TestVintageFilter::testGetFilterDescription(){
    QVERIFY(filter_.getFilterDescription()=="curves=r='0/0,11 ,42/,51 1/0,95':g='0,50/0,48':b='0/0,22 ,49/,44 1/0,8'");
}
