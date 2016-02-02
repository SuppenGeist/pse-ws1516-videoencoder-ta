#include "Yuv422Vector.h"


Utility::Yuv422Vector::Yuv422Vector():Yuv422Vector(0,0,0,0)
{

}

Utility::Yuv422Vector::Yuv422Vector(uint8_t u, uint8_t y1, uint8_t v, uint8_t y2):u_(u),y1_(y1),v_(v),y2_(y2)
{

}

uint8_t Utility::Yuv422Vector::getU()
{
    return u_;
}

uint8_t Utility::Yuv422Vector::getY1()
{
    return y1_;
}

uint8_t Utility::Yuv422Vector::getV()
{
    return v_;
}

uint8_t Utility::Yuv422Vector::getY2()
{
    return y2_;
}

void Utility::Yuv422Vector::setU(uint8_t u)
{
    u_=u;
}

void Utility::Yuv422Vector::setY1(uint8_t y1)
{
    y1_=y1;
}

void Utility::Yuv422Vector::setV(uint8_t v)
{
    v_=v;
}

void Utility::Yuv422Vector::setY2(uint8_t y2)
{
    y2_=y2;
}
