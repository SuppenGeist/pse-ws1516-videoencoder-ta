#include "testyuv422filereader.h"

#include "../../src/utility/Yuv422FileReader.h"
#include "../../src/utility/Yuv422Vector.h"

void TestYuv422FileReader::init() {

}

void TestYuv422FileReader::testYuv422ToRgb888() {
	unsigned char a = 17;
	unsigned char b = 129;
	Utility::Yuv422Vector vec(b,a,b,a);

	std::vector<QRgb> rgbVec = Utility::Yuv422FileReader::Yuv422ToRgb888(vec);
	QVERIFY(rgbVec.size() == 2);


	QVERIFY(qRed(rgbVec.front())== 2);
	QVERIFY(qGreen(rgbVec.front())== 0);
	QVERIFY(qBlue(rgbVec.front())== 3);

	QVERIFY(qRed(rgbVec.back())== 2);
	QVERIFY(qGreen(rgbVec.back())== 0);
	QVERIFY(qBlue(rgbVec.back())== 3);

}
