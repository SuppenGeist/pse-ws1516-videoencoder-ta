#ifndef TESTENCODEDVIDEO_H
#define TESTENCODEDVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/EncodedVideo.h"

class TestEncodedVideo : public QObject
{
    Q_OBJECT

private slots:
    void init();
};

#endif // TESTENCODEDVIDEO_H