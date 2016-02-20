#ifndef TESTVIDEO_H
#define TESTVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/Video.h"

class TestVideo : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void testFPS();
    void TestGetFrame();
    void TestAppendFrame();
    void TestInsertFrame();
    void TestGetNumberOfFrames();
    void TestIsComplete();
    void TestInsertFrames();
    void TestRemoveFrame();
    void TestHeight();
    void TestWidth();

private:
  Model::Video   video_;
};

#endif // TESTVIDEO_H
