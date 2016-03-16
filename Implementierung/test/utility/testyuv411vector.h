#ifndef TESTYUV411VECTOR_H
#define TESTYUV411VECTOR_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/Yuv411Vector.h"

class TestYuv411Vector : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetU();

	void testSetY1();

	void testSetY2();

	void testSetV();

	void testSetY3();

	void testSetY4();

  private:
	Utility::Yuv411Vector vector_;

};

#endif // TESTYUV411VECTOR_H
