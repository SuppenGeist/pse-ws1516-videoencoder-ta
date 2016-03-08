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
void TestMainWindow::clickButton(QString text, QObject* parent) {
    QList<QPushButton*> buttonList = parent->findChildren<QPushButton*>();
    QPushButton* button;
    for(int i = 0; i < buttonList.length() ; i++) {
        if(buttonList.at(i)->text() == text) {
            button = buttonList.at(i);
        }
    }
    QVERIFY2(button != NULL,  (QString("button with text \"")+ text + QString("\" not found")).toLatin1().data());
    button->clicked();
    qApp->processEvents();
    QTest::qSleep(500);
}
GUI::MainWindow* TestMainWindow::getCurrentMainWindow(){
    return mainWindow;
}

void TestMainWindow::triggerAction(QString text, QObject* parent) {
    QList<QAction*> actionList = parent->findChildren<QAction*>();
    QAction* action;
    for(int i = 0; i < actionList.length() ; i++) {
        if(actionList.at(i)->text() == text) {
            action = actionList.at(i);
        }
    }
    QVERIFY2(action != NULL,  (QString("action with text \"")+ text + QString("\" not found")).toLatin1().data());
    action->trigger();
    qApp->processEvents();
    QTest::qSleep(500);
}

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


