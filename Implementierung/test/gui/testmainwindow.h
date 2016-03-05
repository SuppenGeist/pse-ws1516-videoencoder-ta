#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QObject>
#include <QtTest/QtTest>
#include "../../src/gui/MainWindow.h"

class TestMainWindow : public QObject {
    Q_OBJECT

  private slots:
    void init();
    void testAddFilterWithoutVid();
    void testSwitchTab();
 private:
    GUI::MainWindow* mw;
};

#endif // TESTMAINWINDOW_H
