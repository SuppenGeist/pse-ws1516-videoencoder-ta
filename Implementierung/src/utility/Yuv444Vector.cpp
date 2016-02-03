#include "Yuv444Vector.h"

#include <cstdint>

Utility::Yuv444Vector::Yuv444Vector():Yuv444Vector(0,0,0) {

}

Utility::Yuv444Vector::Yuv444Vector(char y, char u, char v):y_(y),u_(u),v_(v){

}

char Utility::Yuv444Vector::getY()
{
    return y_;
}

char Utility::Yuv444Vector::getU()
{
    return u_;
}

char Utility::Yuv444Vector::getV()
{
    return v_;
}

void Utility::Yuv444Vector::setY(char y)
{
    y_=y;
}

void Utility::Yuv444Vector::setU(char u)
{
    u_=u;
}

void Utility::Yuv444Vector::setV(char v)
{
    v_=v;
}
