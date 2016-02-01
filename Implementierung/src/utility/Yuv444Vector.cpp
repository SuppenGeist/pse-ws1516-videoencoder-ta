#include "Yuv444Vector.h"

Utility::Yuv444Vector::Yuv444Vector(char y,char u,char v){
    this->y = y;
    this->u = u;
    this->v = v;
}


uint8_t Utility::Yuv444Vector::getY()
{
    return this->y;
}

uint8_t Utility::Yuv444Vector::getU()
{
    return this->u;
}

uint8_t Utility::Yuv444Vector::getV()
{
    return this->v;
}
