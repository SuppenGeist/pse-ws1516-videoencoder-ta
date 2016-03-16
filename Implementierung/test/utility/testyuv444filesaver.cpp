#include "testyuv444filesaver.h"

#include "../../src/utility/Yuv444FileSaver.h"
#include "../../src/utility/Yuv444Vector.h"
#include <QColor>

void TestYuv444FileSaver::init() {
	pixel = qRgb (1,1,1);
}

void TestYuv444FileSaver::testRgb888ToYuv444() {
	auto vector = Utility::Yuv444FileSaver::Rgb888ToYuv444(pixel);
	QVERIFY(vector.getY() == 16);
	QVERIFY(vector.getU() == 128);
	QVERIFY(vector.getV() == 128);

}

