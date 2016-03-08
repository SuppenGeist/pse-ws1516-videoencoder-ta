#include "testmainwindow.h"

#include <QApplication>
#include <QMouseEvent>
#include <memory>
#include <QPoint>
#include <QTabWidget>
#include <QPushButton>
#include <QList>
#include <typeinfo>
#include <QtConcurrent/QtConcurrent>
#include "../../src/memento/MainWindowMemento.h"

GUI::MainWindow* TestMainWindow::mainWindow;
std::unique_ptr<Memento::MainWindowMemento> TestMainWindow::originMemento;
void TestMainWindow::init() {
    mw = getMainWindow();

}
void TestMainWindow::testAddFilterWithoutVid() {
    std::unique_ptr<Memento::MainWindowMemento> oldMemo = mw->getMemento();
    qApp->processEvents();
    QTest::qSleep(500);
    QList<QPushButton*> buttonList = mw->findChildren<QPushButton*>();
    QPushButton* addBlurFilterButton;
    for(int i = 0; i < buttonList.length() ; i++) {
        if(buttonList.at(i)->text() == "Add Blur filter") {
            addBlurFilterButton = buttonList.at(i);
        }
    }
    QVERIFY2(addBlurFilterButton != NULL, "Add Blur filter button not found");
    if(addBlurFilterButton != NULL) {
        addBlurFilterButton->clicked();
    }
    qApp->processEvents();
    QTest::qSleep(500);
    std::unique_ptr<Memento::MainWindowMemento> newMemo = mw ->getMemento();

    QVERIFY2(oldMemo->getFilterTabMemento()->getFilterList()->getSize() == newMemo->getFilterTabMemento()->getFilterList()->getSize(), "filter got added without picking a video");
    QVERIFY2(newMemo->getFilterTabMemento()->isPreviewShow() == oldMemo->getFilterTabMemento()->isPreviewShow(),"shows preview");

}
void TestMainWindow::testSwitchTab() {

    std::unique_ptr<Memento::MainWindowMemento> oldMemo = mw->getMemento();
    QTest::qSleep(500);
    //the tab widget we need is always the first as the search is recursiv
    QTabWidget* tabWidget = mw->findChildren<QTabWidget*>().first();
    tabWidget->setCurrentIndex(1);
    qApp->processEvents();
    QTest::qSleep(500);
    std::unique_ptr<Memento::MainWindowMemento> newMemo = mw ->getMemento();
    QVERIFY(oldMemo->getSelectedTab() != newMemo->getSelectedTab());

}
GUI::MainWindow* TestMainWindow::getMainWindow() {
    if(mainWindow){
        mainWindow->restore(&*originMemento);
        qApp->processEvents();
    } else {
        mainWindow = new GUI::MainWindow();
        originMemento = mainWindow->getMemento();
        mainWindow->show();
        QTest::qWaitForWindowActive(mainWindow);
    }

    return mainWindow;
}
void TestMainWindow::testLoadVideoFilterTab() {
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
    WriteFilePath* writer = new WriteFilePath;
    QString path = QFINDTESTDATA("akiyo_qcif.yuv");
    writer->setPath(path);
    writer->setThread(QThread::currentThread());
    writer->start();
    loadVideo->clicked();

    QCoreApplication::processEvents();
    QTest::qSleep(2000);
    QVERIFY2(path == mw->getMemento()->getFilterTabMemento()->getRawVideo()->getPath(), "Wrong video path");

}


