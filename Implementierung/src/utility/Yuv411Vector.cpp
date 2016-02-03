#include "Yuv411Vector.h"
#include <cstdint>

Utility::Yuv411Vector::Yuv411Vector():Yuv411Vector(0,0,0,0,0,0)
{

}

Utility::Yuv411Vector::Yuv411Vector(char u, char y1, char y2, char v, char y3, char y4):u_(u),y1_(y1),y2_(y2),v_(v),y3_(y3),y4_(y4)
{

}

char Utility::Yuv411Vector::getU()
{
    return u_;
}

char Utility::Yuv411Vector::getY1()
{
    return y1_;
}

char Utility::Yuv411Vector::getY2()
{
    return y2_;
}

char Utility::Yuv411Vector::getV()
{
    return v_;
}

char Utility::Yuv411Vector::getY3()
{
    return y3_;
}

char Utility::Yuv411Vector::getY4()
{
    return y4_;
}

void Utility::Yuv411Vector::setU(char u)
{
    u_=u;
}

void Utility::Yuv411Vector::setY1(char y1)
{
    y1_=y1;
}

void Utility::Yuv411Vector::setY2(char y2)
{
    y2_=y2;
}

void Utility::Yuv411Vector::setV(char v)
{
    v_=v;
}

void Utility::Yuv411Vector::setY3(char y3)
{
    y3_=y3;
}

void Utility::Yuv411Vector::setY4(char y4)
{
    y4_=y4;
}
