#include "Yuv422Vector.h"


Utility::Yuv422Vector::Yuv422Vector():Yuv422Vector(0,0,0,0) {

}

Utility::Yuv422Vector::Yuv422Vector(unsigned char u, unsigned char y1, unsigned char v,
                                    unsigned char y2):u_(u),y1_(y1),v_(v),y2_(y2) {

}

unsigned char Utility::Yuv422Vector::getU() {
	return u_;
}

unsigned char Utility::Yuv422Vector::getY1() {
	return y1_;
}

unsigned char Utility::Yuv422Vector::getV() {
	return v_;
}

unsigned char Utility::Yuv422Vector::getY2() {
	return y2_;
}

void Utility::Yuv422Vector::setU(unsigned char u) {
	u_=u;
}

void Utility::Yuv422Vector::setY1(unsigned char y1) {
	y1_=y1;
}

void Utility::Yuv422Vector::setV(unsigned char v) {
	v_=v;
}

void Utility::Yuv422Vector::setY2(unsigned char y2) {
	y2_=y2;
}
