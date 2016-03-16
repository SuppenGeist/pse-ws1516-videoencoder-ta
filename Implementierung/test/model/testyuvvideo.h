#ifndef TESTYUVVIDEO_H
#define TESTYUVVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/YuvVideo.h"

class TestYuvVideo : public QObject {
	Q_OBJECT

  private slots:
	void init();
	void testgetCompression();
	void testgetYuvType();
	void testgetWidth();
	void testgetHeight();
	void tesgetFps();
  private:
	Model::YuvVideo* yuvVideo_;
};

#endif // TESTYUVVIDEO_H
