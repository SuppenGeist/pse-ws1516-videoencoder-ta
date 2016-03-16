#ifndef TESTYUV444VECTOR_H
#define TESTYUV444VECTOR_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/Yuv444Vector.h"

class TestYuv444Vector : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testSetY();

	void testSetU();

	void testSetV();

  private:
	Utility::Yuv444Vector vector_;

};

#endif // TESTYUV444VECTOR_H
