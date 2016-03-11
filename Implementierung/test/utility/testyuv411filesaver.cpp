#include "testyuv411filesaver.h"

#include "../../src/utility/Yuv411FileSaver.h"
#include "../../src/utility/Yuv411Vector.h"
#include <QColor>

void TestYuv411FileSaver::init() {
    pixel1 = qRgb (1,1,1);
    pixel2 = qRgb (1,1,1);
    pixel3 = qRgb (1,1,1);
    pixel4 = qRgb (1,1,1);
}

void TestYuv411FileSaver::testRgb888ToYuv411() {
    auto vector = Utility::Yuv411FileSaver::Rgb888ToYuv411(pixel1,pixel2,pixel3,pixel4);
    QVERIFY(vector.getY1() == 16);
    QVERIFY(vector.getU() == 128);
    QVERIFY(vector.getV() == 128);
    QVERIFY(vector.getY2() == 16);
    QVERIFY(vector.getY3() == 16);
    QVERIFY(vector.getY4() == 16);
}

