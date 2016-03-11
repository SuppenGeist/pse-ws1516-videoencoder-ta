#include "testyuv422filesaver.h"

#include "../../src/utility/Yuv422FileSaver.h"
#include "../../src/utility/Yuv422Vector.h"
#include <QColor>

void TestYuv422FileSaver::init() {
    pixel1 = qRgb (1,1,1);
    pixel2 = qRgb (1,1,1);
}

void TestYuv422FileSaver::testRgb888ToYuv422() {
    auto vector = Utility::Yuv422FileSaver::Rgb888ToYuv422(pixel1, pixel2);
    QVERIFY(vector.getY1() == 16);
    QVERIFY(vector.getU() == 128);
    QVERIFY(vector.getV() == 128);
    QVERIFY(vector.getY2() == 16);

}
