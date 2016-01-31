#include "Yuv444Vector.h"

Utility::Yuv444Vector::Yuv444Vector(uint8_t y,uint8_t u,uint8_t v){
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
