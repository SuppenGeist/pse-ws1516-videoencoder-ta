#ifndef TESTMAINWINDOWMEMENTO_H
#define TESTMAINWINDOWMEMENTO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/memento/MainWindowMemento.h"

class TestMainWindowMemento : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetSelectedTab();

	void testSetAnalysisTab();

	void testSetFilterTab();


  private:
	Memento::MainWindowMemento memento_;

};

#endif // TESTMAINWINDOWMEMENTO_H
