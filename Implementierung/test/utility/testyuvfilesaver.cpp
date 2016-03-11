#include "testyuvfilesaver.h"
#include "../../src/utility/YuvFileSaver.h"
#include <QColor>

void TestYuvFileSaver::init() {
    pixel = qRgb (1,1,1);
}

void TestYuvFileSaver::testRgbToY() {
    int a = 0.257 + 0.504 + 0.098 + 16;
    QVERIFY(Utility::YuvFileSaver::RgbToY(pixel) == a);

}

void TestYuvFileSaver::testRgbToU() {
    int b = -0.148 - 0.291 + 0.439 + 128;
    QVERIFY(Utility::YuvFileSaver::RgbToU(pixel) == b);

}

void TestYuvFileSaver::testRgbToV() {
    int c = 0.439 - 0.368 - 0.071 + 128;
    QVERIFY(Utility::YuvFileSaver::RgbToV(pixel) == c);

}
