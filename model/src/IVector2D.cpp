#include "IVector2D.h"

void IVector2D::set(int x,int y)
{
    this->x = x;
    this->y = y;
}

int IVector2D::operator==(const IVector2D &vector) const {
    return (x == vector.x)&&(y == vector.y);
}
