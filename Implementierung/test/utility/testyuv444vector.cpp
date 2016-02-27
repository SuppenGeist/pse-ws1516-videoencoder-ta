#include "testyuv444vector.h"

void TestYuv444Vector::init() {

    vector_ = Utility::Yuv444Vector();
}

void TestYuv444Vector::testSetY(){
    unsigned char value = 42;
    vector_.setY(value);
    QVERIFY(vector_.getY() == value);
}

void TestYuv444Vector::testSetU(){
    unsigned char value = 43;
    vector_.setU(value);
    QVERIFY(vector_.getU() == value);

}

void TestYuv444Vector::testSetV(){
    unsigned char value = 44;
    vector_.setV(value);
    QVERIFY(vector_.getV() == value);

}
