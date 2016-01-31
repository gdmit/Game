#include "IVector2D.h"

IVector2D IVector2D::zero(0, 0);
IVector2D IVector2D::one (1, 1);

void IVector2D::set(int x,int y) {
    this->x = x;
    this->y = y;
}

int IVector2D::operator==(const IVector2D &vector) const {
    return (x == vector.x)&&(y == vector.y);
}

IVector2D& IVector2D::operator=(const IVector2D& vector) {
    x = vector.x;
    y = vector.y;

    return *this;
}

IVector2D IVector2D::operator+() const {
    return *this;
}

IVector2D IVector2D::operator-() const {
    return IVector2D ( -x, -y );
}

IVector2D& IVector2D::operator+=(const IVector2D& vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}

IVector2D& IVector2D::operator-=(const IVector2D& vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}

IVector2D& IVector2D::operator*=(const IVector2D& vector) {
    x *= vector.x;
    y *= vector.y;

    return *this;
}

IVector2D& IVector2D::operator*=(int value) {
    x *= value;
    y *= value;

    return *this;
}

IVector2D& IVector2D::operator/=(const IVector2D& vector) {
    x /= vector.x;
    y /= vector.y;

    return *this;
}

IVector2D& IVector2D::operator/=(int value) {
    x /= value;
    y /= value;

    return *this;
}

int& IVector2D::operator[](int index) {
    return * ( index + &x );
}

int	IVector2D::operator!=(const IVector2D& vector) const {
    return x != vector.x || y != vector.y;
}

IVector2D::operator int*() {
    return &x;
}

IVector2D::operator const int*() const {
    return &x;
}

float IVector2D::length() const {
    return (float) sqrt (x*x + y*y);
}

float IVector2D::lengthSquare() const {
    return x * x + y * y;
}

IVector2D& IVector2D::normalize() {
    return (*this) /= length();
}

int IVector2D::maxLength() const {
    return max(abs(x), abs(y));
}

int IVector2D::max(int a, int b ) const {
    return a > b ? a : b;
}

int IVector2D::min(int a, int b) const {
    return a < b ? a : b;
}

int IVector2D::sqr(int x) const {
    return x*x;
}


inline IVector2D operator+(const IVector2D& u, const IVector2D& v) {
    return IVector2D(u.x + v.x, u.y + v.y);
}

inline IVector2D operator-(const IVector2D& u, const IVector2D& v) {
    return IVector2D(u.x - v.x, u.y - v.y);
}

inline IVector2D operator*(const IVector2D& u, const IVector2D& v) {
    return IVector2D(u.x* v.x, u.y* v.y);
}

inline IVector2D operator*(const IVector2D& vector, int value) {
    return IVector2D(vector.x * value, vector.y * value);
}

inline IVector2D operator*(int value, const IVector2D& vector) {
    return IVector2D(vector.x * value, vector.y * value);
}

inline IVector2D operator/(const IVector2D& u, const IVector2D& v) {
    return IVector2D(u.x / v.x, u.y / v.y);
}

inline IVector2D operator/(const IVector2D& vector, int value) {
    return IVector2D (vector.x / value, vector.y / value);
}

inline IVector2D operator/(int value, const IVector2D& vector) {
    return IVector2D (value / vector.x, value / vector.y );
}

inline int operator&(const IVector2D& u, const IVector2D& v) {
    return u.x*v.x + u.y*v.y;
}