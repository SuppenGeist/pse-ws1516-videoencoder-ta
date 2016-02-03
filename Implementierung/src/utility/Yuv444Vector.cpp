#include "Yuv444Vector.h"

#include <cstdint>

Utility::Yuv444Vector::Yuv444Vector():Yuv444Vector(0,0,0) {

}

Utility::Yuv444Vector::Yuv444Vector(uint8_t y,uint8_t u,uint8_t v):y_(y),u_(u),v_(v){

}

uint8_t Utility::Yuv444Vector::getY()
{
    return y_;
}

uint8_t Utility::Yuv444Vector::getU()
{
    return u_;
}

uint8_t Utility::Yuv444Vector::getV()
{
    return v_;
}

void Utility::Yuv444Vector::setY(uint8_t y)
{
    y_=y;
}

void Utility::Yuv444Vector::setU(uint8_t u)
{
    u_=u;
}

void Utility::Yuv444Vector::setV(uint8_t v)
{
    v_=v;
}
