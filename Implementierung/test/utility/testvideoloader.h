#ifndef TESTVIDEOLOADER_H
#define TESTVIDEOLOADER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/EncodedVideo.h"

class TestVideoLoader : public QObject
{
    Q_OBJECT

private slots:
  void init();
  void testgetCodec();
  void testgetAverageBitrate();

private:
 Utility::VideoLoader* videoLoader_;
};

#endif // TESTVIDEOLOADER_H
