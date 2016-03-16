#include "testyuvfilereader.h"
#include "../../src/utility/YuvFileReader.h"

void TestYuvFileReader::init() {

}

void TestYuvFileReader::testClamp() {
	int a = -1;
	int b = 300;
	int c = 0;
	int d = 255;

	QVERIFY(Utility::YuvFileReader::clamp(a) != a);
	QVERIFY(Utility::YuvFileReader::clamp(b) != b);
	QVERIFY(Utility::YuvFileReader::clamp(c) == c);
	QVERIFY(Utility::YuvFileReader::clamp(d) == d);

}
