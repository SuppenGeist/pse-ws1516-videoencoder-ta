#ifndef TESTYUV422VECTOR_H
#define TESTYUV422VECTOR_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/Yuv422Vector.h"

class TestYuv422Vector : public QObject {
    Q_OBJECT

  private slots:
    void init();

    void testSetU();

    void testSetY1();

    void testSetV();

    void testSetY2();

  private:
    Utility::Yuv422Vector vector_;

};

#endif // TESTYUV422VECTOR_H
