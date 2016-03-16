#include "testyuv411filereader.h"

#include "../../src/utility/Yuv411FileReader.h"
#include "../../src/utility/Yuv411Vector.h"

void TestYuv411FileReader::init() {

}

void TestYuv411FileReader::testYuv411ToRgb888() {
	unsigned char a = 17;
	unsigned char b = 129;
	Utility::Yuv411Vector vec(b,a,a,b,a,a);

	std::vector<QRgb> rgbVec = Utility::Yuv411FileReader::Yuv411ToRgb888(vec);
	QVERIFY(rgbVec.size() == 4);


	QVERIFY(qRed(rgbVec.front())== 2);
	QVERIFY(qGreen(rgbVec.front())== 0);
	QVERIFY(qBlue(rgbVec.front())== 3);

	auto rgb2 = rgbVec[1];
	QVERIFY(qRed(rgb2)== 2);
	QVERIFY(qGreen(rgb2)== 0);
	QVERIFY(qBlue(rgb2)== 3);

	auto rgb3 = rgbVec[2];
	QVERIFY(qRed(rgb3)== 2);
	QVERIFY(qGreen(rgb3)== 0);
	QVERIFY(qBlue(rgb3)== 3);

	QVERIFY(qRed(rgbVec.back())== 2);
	QVERIFY(qGreen(rgbVec.back())== 0);
	QVERIFY(qBlue(rgbVec.back())== 3);
}
