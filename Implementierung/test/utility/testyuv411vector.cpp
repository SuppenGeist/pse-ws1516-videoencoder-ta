#include "testyuv411vector.h"

void TestYuv411Vector::init() {

	vector_ = Utility::Yuv411Vector();
}

void TestYuv411Vector::testSetU() {
	unsigned char value = 42;
	vector_.setU(value);
	QVERIFY(vector_.getU() == value);
}

void TestYuv411Vector::testSetY1() {
	unsigned char value = 43;
	vector_.setY1(value);
	QVERIFY(vector_.getY1() == value);
}

void TestYuv411Vector::testSetY2() {
	unsigned char value = 44;
	vector_.setY2(value);
	QVERIFY(vector_.getY2() == value);
}

void TestYuv411Vector::testSetV() {
	unsigned char value = 45;
	vector_.setV(value);
	QVERIFY(vector_.getV() == value);
}

void TestYuv411Vector::testSetY3() {
	unsigned char value = 46;
	vector_.setY3(value);
	QVERIFY(vector_.getY3() == value);
}

void TestYuv411Vector::testSetY4() {
	unsigned char value = 47;
	vector_.setY4(value);
	QVERIFY(vector_.getY4() == value);
}
