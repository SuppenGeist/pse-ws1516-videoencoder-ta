#include "testmainwindow.h"

#include <QApplication>
#include <QMouseEvent>
#include <memory>
#include <QPoint>
#include <QTabWidget>
#include <QPushButton>
#include <QList>
#include "../../src/memento/MainWindowMemento.h"


void TestMainWindow::init() {
    mw = new GUI::MainWindow;
    mw->show();
    QTest::qWaitForWindowActive(mw);

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
    delete mw;

}
void TestMainWindow::testSwitchTab() {

    std::unique_ptr<Memento::MainWindowMemento> oldMemo = mw->getMemento();
    QTest::qSleep(500);
    QTabWidget* tabWidget = mw->findChildren<QTabWidget*>().first();
    tabWidget->setCurrentIndex(1);
    qApp->processEvents();
    QTest::qSleep(500);
    std::unique_ptr<Memento::MainWindowMemento> newMemo = mw ->getMemento();

    QVERIFY(oldMemo->getSelectedTab() != newMemo->getSelectedTab());
    delete mw;
}
