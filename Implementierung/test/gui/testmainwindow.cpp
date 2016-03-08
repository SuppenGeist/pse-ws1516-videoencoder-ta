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


