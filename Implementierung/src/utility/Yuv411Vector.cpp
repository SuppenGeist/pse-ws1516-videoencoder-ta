#include "Yuv411Vector.h"
#include <cstdint>

Utility::Yuv411Vector::Yuv411Vector():Yuv411Vector(0,0,0,0,0,0)
{

}

Utility::Yuv411Vector::Yuv411Vector(unsigned char u, unsigned char y1, unsigned char y2, unsigned char v, unsigned char y3, unsigned char y4):u_(u),y1_(y1),y2_(y2),v_(v),y3_(y3),y4_(y4)
{

}

unsigned char Utility::Yuv411Vector::getU()
{
    return u_;
}

unsigned char Utility::Yuv411Vector::getY1()
{
    return y1_;
}

unsigned char Utility::Yuv411Vector::getY2()
{
    return y2_;
}

unsigned char Utility::Yuv411Vector::getV()
{
    return v_;
}

unsigned char Utility::Yuv411Vector::getY3()
{
    return y3_;
}

unsigned char Utility::Yuv411Vector::getY4()
{
    return y4_;
}

void Utility::Yuv411Vector::setU(unsigned char u)
{
    u_=u;
}

void Utility::Yuv411Vector::setY1(unsigned char y1)
{
    y1_=y1;
}

void Utility::Yuv411Vector::setY2(unsigned char y2)
{
    y2_=y2;
}

void Utility::Yuv411Vector::setV(unsigned char v)
{
    v_=v;
}

void Utility::Yuv411Vector::setY3(unsigned char y3)
{
    y3_=y3;
}

void Utility::Yuv411Vector::setY4(unsigned char y4)
{
    y4_=y4;
}
