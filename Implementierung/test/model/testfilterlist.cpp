#include "testfilterlist.h"

#include <memory>

#include "../../src/model/filters/Filter.h"
#include "../../src/model/filters/EdgeFilter.h"
#include "../../src/model/filters/BlurFilter.h"

void TestFilterList::init(){
    filterList_ = new Model::FilterList();
    filterList_->appendFilter(QString("Blur"));
    filterList_->appendFilter(QString("Edge"));
}

void TestFilterList::testGetFilter(){
    QVERIFY(filterList_->getFilter(0)->getName() == "Blur");
    QVERIFY(filterList_->getFilter(1)->getName() == "Edge");
    QVERIFY(filterList_->getFilter(2) == 0);
}

void TestFilterList::testConstructor(){
    Model::FilterList* filterListTmp = new Model::FilterList(*filterList_);
    QVERIFY(filterList_->getFilter(0)->getName() == filterListTmp->getFilter(0)->getName());
    QVERIFY(filterList_->getFilter(1)->getName() == filterListTmp->getFilter(1)->getName());
}

void TestFilterList::testMoveFilter(){
    filterList_->moveFilter(1,0);
    QVERIFY(filterList_->getFilter(1)->getName() == "Blur");
    filterList_->moveFilter(1,2);
    QVERIFY(filterList_->getFilter(1)->getName() == "Blur");
    filterList_->moveFilter(0,1);
    QVERIFY(filterList_->getFilter(0)->getName() == "Blur");
    QVERIFY(filterList_->getFilter(1)->getName() == "Edge");

}

void TestFilterList::testInsertFilter(){
    std::unique_ptr<Model::Filter> filter = std::move(Model::Filter::CreateFilter("Grid"));
    filterList_->insertFilter(std::move(filter),1);
    QVERIFY(filterList_->getFilter(0)->getName() == "Blur");
    QVERIFY(filterList_->getFilter(1)->getName() == "Grid");
    QVERIFY(filterList_->getFilter(2)->getName() == "Edge");
    filterList_->removeFilter(1);
    QVERIFY(filterList_->getFilter(0)->getName() == "Blur");
    QVERIFY(filterList_->getFilter(1)->getName() == "Edge");
    QVERIFY(filterList_->getFilter(2) == 0);
}

void TestFilterList::testAppendFilter(){
    filterList_ = new Model::FilterList();
    filterList_->appendFilter(QString("Blur"));
    filterList_->appendFilter(QString("Edge"));
    QVERIFY(filterList_->getFilter(0)->getName() == "Blur");
    QVERIFY(filterList_->getFilter(1)->getName() == "Edge");
}

void TestFilterList::testGetSize(){
    QVERIFY(filterList_->getSize() == 2);
    filterList_= new Model::FilterList();
    QVERIFY(filterList_->getSize() == 0);
    filterList_->appendFilter(QString("Blur"));
    filterList_->appendFilter(QString("Edge"));
}
