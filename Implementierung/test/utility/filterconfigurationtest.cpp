#include "filterconfigurationtest.h"

#include "../../src/model/FilterList.h"
#include "../../src/model/filters/Filter.h"
#include "../../src/model/filters/EdgeFilter.h"
#include "../../src/model/filters/BlurFilter.h"

void FilterConfigurationTest::init()
{
    QString path_ = QFINDTESTDATA("Configtest.txt");
    Model::FilterList filterList_;
    filterList_.appendFilter(QString("Blur"));
    filterList_.appendFilter(QString("Edge"));
    configSaver_ = new Utility::FilterConfigurationSaver(path_,filterList_);
    configLoader_ = new Utility::FilterConfigurationLoader(path_);
}

void FilterConfigurationTest::testSaverLoader(){
    configSaver_->save();
    std::unique_ptr<Model::FilterList> filterlist1 = configLoader_->getConfiguration();
    Model::FilterList* filterList1_ = filterlist1.release();
    QVERIFY(filterList1_->getFilter(0)->getName() == "Blur");
    QVERIFY(filterList1_->getFilter(1)->getName() == "Edge");
    QVERIFY(filterList1_->getFilter(2) == 0);
}
