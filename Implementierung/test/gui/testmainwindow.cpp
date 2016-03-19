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
#include "testanalysistab.h"
#include "testfiltertab.h"

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
	QVERIFY2(button != NULL,  (QString("button with text \"")+ text +
	                           QString("\" not found")).toLatin1().data());
	button->clicked();
	qApp->processEvents();
	QTest::qSleep(500);
}
void TestMainWindow::waitForWindow(int time) {
	QTest::qSleep(time * 2 / 3);
	qApp->processEvents();
	QTest::qSleep(time / 3);
}

GUI::MainWindow* TestMainWindow::getCurrentMainWindow() {
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
	QVERIFY2(action != NULL,  (QString("action with text \"")+ text +
	                           QString("\" not found")).toLatin1().data());
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
	if(mainWindow) {
        triggerAction("New");
        QTabWidget* tabWidget = mainWindow->findChildren<QTabWidget*>().first();
        tabWidget->setCurrentIndex(0);
		qApp->processEvents();
	} else {
		mainWindow = new GUI::MainWindow();
		originMemento = mainWindow->getMemento();
		mainWindow->show();
		QTest::qWaitForWindowActive(mainWindow);
	}
    waitForWindow(300);
	return mainWindow;
}
void TestMainWindow::testCrazyMonkeyClicks() {
    clickButton("Apply to video");
    clickButton("Filter up");
    clickButton("Apply to video");
    clickButton("Filter down");
    clickButton("Save configuration");
    clickButton("Add Edge filter");
    QTabWidget* tabWidget = mw->findChildren<QTabWidget*>().first();
    tabWidget->setCurrentIndex(1);
    clickButton("PSNR");
    clickButton("Bitrate");
    clickButton("Red histogram");
    TestAnalysisTab::loadVideo(QFINDTESTDATA("blumeYuv420_planar_176x144.yuv"));
    clickButton("PSNR");
    clickButton("Bitrate");
    clickButton("Red histogram");
    tabWidget->setCurrentIndex(0);
    clickButton("Remove filter");
    clickButton("Save configuration");
    clickButton("Add Contrast filter");
    TestFilterTab::loadVideo(QFINDTESTDATA("blumeYuv420_planar_176x144.yuv"));
    clickButton("Add Vintage filter");
    clickButton("Apply to video");
    triggerAction("Redo");
    triggerAction("Redo");
    triggerAction("Redo");
    clickButton("Add Vintage filter");
    triggerAction("Redo");
    triggerAction("Undo");
    tabWidget->setCurrentIndex(1);
    triggerAction("New");
    clickButton("Add video");





}


