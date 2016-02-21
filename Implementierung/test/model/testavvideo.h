#ifndef TESTAVVIDEO_H
#define TESTAVVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/AVVideo.h"

class TestAVVideo : public QObject {
	Q_OBJECT

  private slots:
	void init();
    void TestFPS();
	void TestRemoveFrame();
	void TestAppendFrame();
	void TestInsertFrame();
	void TestGetNumberOfFrames();
	void TestGetFrame();
	void TestIsComplete();
	void TestInsertFrames();
	void TestHeight();
	void TestWidth();


  private:
	Model::AVVideo   avvideo_;

};

#endif // TESTAVVIDEO_H
