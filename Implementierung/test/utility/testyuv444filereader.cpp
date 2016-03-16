#include "testyuv444filereader.h"

#include "../../src/utility/Yuv444FileReader.h"
#include "../../src/utility/Yuv444Vector.h"
#include "../../src/utility/Compression.h"
#include <QColor>

void TestYuv444FileReader::init() {

}

void TestYuv444FileReader::testYuv444ToRgb888() {
	unsigned char a = 17;
	unsigned char b = 129;
	Utility::Yuv444Vector vec(a,b,b);

	QRgb rgb = Utility::Yuv444FileReader::Yuv444ToRgb888(vec);
	QVERIFY(qRed(rgb)== 2);
	QVERIFY(qGreen(rgb)== 0);
	QVERIFY(qBlue(rgb)== 3);

}

