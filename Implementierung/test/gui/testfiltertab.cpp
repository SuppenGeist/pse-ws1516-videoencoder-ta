#include "testfiltertab.h"

#include "testmainwindow.h"
void TestFilterTab::clickItemInFilterList(int index) {
    QList<QListView*> listViewList = TestMainWindow::getCurrentMainWindow()->findChildren<QListView*>();
    QListView* listView;
    for(int i = 0; i < listViewList.length() ; i++) {
        if(listViewList.at(i)->objectName() == "list_filterlist_") {
            listView = listViewList.at(i);
        }
    }
    QVERIFY2(listView != NULL, "listview not found");
    listView->setCurrentIndex(listView->indexAt(QPoint(10,10+index*20)));
    qApp->processEvents();
    QTest::qSleep(250);
}

void TestFilterTab::init() {
    mw = TestMainWindow::getMainWindow();

}
void TestFilterTab::loadVideo(QString path) {
    //get LoadVideo button
    QPushButton* loadVideo;
    QList<QPushButton*> buttonList = mw->findChildren<QPushButton*>();
    for(int i = 0; i < buttonList.length() ; i++) {
        if(buttonList.at(i)->text() == "Load video") {
            loadVideo = buttonList.at(i);
        }
    }
    QVERIFY2(loadVideo != NULL,"Could not find load video button");
    QTest::qSleep(500);
    WriteYuvFilePath* writer = new WriteYuvFilePath;
    writer->setPath(path);
    writer->setThread(QThread::currentThread());
    writer->start();
    loadVideo->clicked();

    QCoreApplication::processEvents();
    QTest::qSleep(2000);
    QVERIFY2(path == mw->getMemento()->getFilterTabMemento()->getRawVideo()->getPath(), "Wrong video path");

}
void TestFilterTab::testLoadVideo() {
    //loadVideo(QFINDTESTDATA("akiyo_qcif.yuv"));
}
void TestFilterTab::testAddFilterWithoutVid() {
    std::unique_ptr<Memento::MainWindowMemento> oldMemo = mw->getMemento();
    qApp->processEvents();
    QTest::qSleep(500);

    TestMainWindow::clickButton("Add Blur filter");
    std::unique_ptr<Memento::MainWindowMemento> newMemo = mw ->getMemento();

    QVERIFY2(oldMemo->getFilterTabMemento()->getFilterList()->getSize() == newMemo->getFilterTabMemento()->getFilterList()->getSize(), "filter got added without picking a video");
    QVERIFY2(newMemo->getFilterTabMemento()->isPreviewShow() == oldMemo->getFilterTabMemento()->isPreviewShow(),"shows preview");
}
void TestFilterTab::testAddRemoveFilters(){
    loadVideo(QFINDTESTDATA("akiyo_qcif.yuv"));

    TestMainWindow::clickButton("Add Blur filter");
    TestMainWindow::clickButton("Add Colorbalance filter");
    TestMainWindow::clickButton("Add Border filter");
    QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 3, "error adding filters");
    TestMainWindow::triggerAction("Undo");
    QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 2, "error undoing add filter");
    clickItemInFilterList(1);
    TestMainWindow::clickButton("Remove filter");
    QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 1, "error pressing \"Remove filter\"");
    QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getFilter(0)->getName() == "Blur", "error pressing \"Remove filter\" : wrong filter removed");
    TestMainWindow::triggerAction("Undo");
    QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 2, "error undoing \"Remove filter\"-Press");
    TestMainWindow::triggerAction("Redo");
    QVERIFY2(mw->getMemento()->getFilterTabMemento()->getFilterList()->getSize() == 1, "error redoing \"Remove filter\"-Press");

}
