#ifndef TESTYUVVIDEO_H
#define TESTYUVVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/YuvVideo.h"

class TestYuvVideo : public QObject
{
    Q_OBJECT

private slots:
    void init();
};

#endif // TESTYUVVIDEO_H
