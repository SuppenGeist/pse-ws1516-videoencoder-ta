#ifndef TESTFILTERTAB_H
#define TESTFILTERTAB_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/gui/MainWindow.h"

class TestFilterTab : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void testAddFilterWithoutVid();
    void testLoadVideo();
private:
    GUI::MainWindow* mw;
};

#endif // TESTFILTERTAB_H
