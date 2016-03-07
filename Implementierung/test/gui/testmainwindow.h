#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QObject>
#include <QtTest/QtTest>
#include <memory>
#include "../../src/gui/MainWindow.h"
#include "../../src/memento/MainWindowMemento.h"
class TestMainWindow : public QObject {
    Q_OBJECT
public:
    static GUI::MainWindow* getMainWindow();
  private slots:
    void init();
    void testSwitchTab();
    void testAddFilterWithoutVid();
 private:
    GUI::MainWindow* mw;
    static std::unique_ptr<Memento::MainWindowMemento> originMemento;
    static GUI::MainWindow* mainWindow;
};

#endif // TESTMAINWINDOW_H
