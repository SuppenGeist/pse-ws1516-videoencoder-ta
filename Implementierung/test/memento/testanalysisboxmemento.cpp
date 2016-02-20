#include "testanalysisboxmemento.h"
#include <QString>

void TestAnalysisBoxMemento::init(){

        memento_ = Memento::AnalysisBoxMemento();

}

void TestAnalysisBoxMemento::testSetComment(){
    QString string = "test";
    memento_.setComment(string);
    QVERIFY(memento_.getComment() == string);

}

void TestAnalysisBoxMemento::testSetPath(){
    QString string = "test";
    memento_.setPath(string);
    QVERIFY(memento_.getPath() == string);

}
