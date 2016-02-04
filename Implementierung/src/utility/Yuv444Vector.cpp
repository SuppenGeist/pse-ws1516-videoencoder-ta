#include "Yuv444Vector.h"

#include <cstdint>

Utility::Yuv444Vector::Yuv444Vector():Yuv444Vector(0,0,0) {

}

Utility::Yuv444Vector::Yuv444Vector(unsigned char y, unsigned char u, unsigned char v):y_(y),u_(u),
	v_(v) {

}

unsigned char Utility::Yuv444Vector::getY() {
	return y_;
}

unsigned char Utility::Yuv444Vector::getU() {
	return u_;
}

unsigned char Utility::Yuv444Vector::getV() {
	return v_;
}

void Utility::Yuv444Vector::setY(unsigned char y) {
	y_=y;
}

void Utility::Yuv444Vector::setU(unsigned char u) {
	u_=u;
}

void Utility::Yuv444Vector::setV(unsigned char v) {
	v_=v;
}
