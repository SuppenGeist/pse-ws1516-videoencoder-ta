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

private:
  Model::Video   video_;
};

#endif // TESTVIDEO_H
