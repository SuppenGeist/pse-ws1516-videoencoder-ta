#include "testyuv422vector.h"

void TestYuv422Vector::init() {

	vector_ = Utility::Yuv422Vector();
}

void TestYuv422Vector::testSetU() {
	unsigned char value = 42;
	vector_.setU(value);
	QVERIFY(vector_.getU() == value);
}

void TestYuv422Vector::testSetY1() {
	unsigned char value = 43;
	vector_.setY1(value);
	QVERIFY(vector_.getY1() == value);
}

void TestYuv422Vector::testSetV() {
	unsigned char value = 44;
	vector_.setV(value);
	QVERIFY(vector_.getV() == value);

}

void TestYuv422Vector::testSetY2() {
	unsigned char value = 45;
	vector_.setY2(value);
	QVERIFY(vector_.getY2() == value);
}
