#ifndef TESTAVVIDEO_H
#define TESTAVVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/AVVideo.h"

class TestAVVideo : public QObject {
	Q_OBJECT

  private slots:
	void init();
    void testFPS();
    void testRemoveFrame();
    void testAppendFrame();
    void testInsertFrame();
	void testGetNumberOfFrames();
	void testGetFrame();
    void testIsComplete();
	void testHeight();
	void testWidth();


  private:
	Model::AVVideo   avvideo_;

};

#endif // TESTAVVIDEO_H
