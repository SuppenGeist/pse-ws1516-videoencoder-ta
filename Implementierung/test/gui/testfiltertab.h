#ifndef TESTFILTERTAB_H
#define TESTFILTERTAB_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/gui/MainWindow.h"

class TestFilterTab : public QObject
{
    Q_OBJECT
public:
    static void clickItemInFilterList(int index);
private:
    void loadVideo(QString path);
    void clickButton(QString text);
private slots:
    void init();
    void testAddFilterWithoutVid();
    void testLoadVideo();
    void testAddRemoveFilters();
    void testFilterList();
private:
    GUI::MainWindow* mw;
};

#endif // TESTFILTERTAB_H
