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

private:
  Model::AVVideo   avvideo_;

};

#endif // TESTAVVIDEO_H
