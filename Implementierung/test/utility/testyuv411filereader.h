#ifndef TESTYUV411FILEREADER_H
#define TESTYUV411FILEREADER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/Yuv411FileReader.h"

class TestYuv411FileReader : public QObject {
    Q_OBJECT

  private slots:
    void init();

    void testParseNextFrame();

    void testReadNextVectorPacked();

    void testReadNextVectorPlanar();

  private:
    Utility::Yuv411FileReader fileReader_;
    Utility::Yuv411Vector vector_;
};


#endif // TESTYUV411FILEREADER_H
