#ifndef TESTAVVIDEO_H
#define TESTAVVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/AVVideo.h"

class TestAVVideo : public QObject
{
    Q_OBJECT

private slots:
  void init();
  void testFPS();
  void TestInsertFrame();
  void TestAppendFrame();
  void TestRemoveFrame();
  void TestIsComplete();
  void TestInsertFrames();
  void TestHeightWidth();

private:
  Model::AVVideo   avvideo_;

};

#endif // TESTAVVIDEO_H
