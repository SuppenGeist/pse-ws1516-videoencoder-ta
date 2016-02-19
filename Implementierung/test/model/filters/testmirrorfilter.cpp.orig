#include "testmirrorfilter.h"

#include "../../../src/model/filters/MirrorFilter.h"

#include "../../../src/model/MirrorMode.h"

void TestMirrorFilter::init()
{
    filter_=Model::MirrorFilter();
}

void TestMirrorFilter::testGetFilterDescription(){
    filter_.setMode(Model::MirrorMode::VERTICAL);
    QVERIFY(filter_.getFilterDescription()=="vflip");
}

void TestMirrorFilter::testRestore()
{
    filter_.restore("ver");
    QVERIFY(filter_.getMode()==Model::MirrorMode::VERTICAL);

    filter_.restore("hor");
    QVERIFY(filter_.getMode()==Model::MirrorMode::HORIZONTAL);

}

void TestMirrorFilter::testFilterCopy()
{
    const Model::MirrorMode mode = Model::MirrorMode::VERTICAL;
    Model::MirrorFilter filter2;
    filter2.setMode(mode);

    filter_.restore(filter2.getSaveString());
    QVERIFY(filter_.getMode()==mode);
}
