// Copyright (c) 2016 Evolution Team. All rights reserved.

#include <algorithm>
#include "../include/IVector2D.h"

IVector2D IVector2D::zero(0, 0);
IVector2D IVector2D::one(1, 1);

void IVector2D::set(int x, int y) {
    this->x = x;
    this->y = y;
}

int IVector2D::operator==(const IVector2D &vector) const {
    return (x == vector.x) && (y == vector.y);
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
    return IVector2D(-x, -y);
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
    return *(index + &x);
}

int IVector2D::operator!=(const IVector2D& vector) const {
    return x != vector.x || y != vector.y;
}

IVector2D::operator int*() {
    return &x;
}

IVector2D::operator const int*() const {
    return &x;
}

float IVector2D::length() const {
    return static_cast<float>(sqrt(x*x + y*y));
}

float IVector2D::lengthSquare() const {
    return x * x + y * y;
}

IVector2D& IVector2D::normalize() {
    return (*this) /= length();
}

int IVector2D::maxLength() const {
    return std::max(abs(x), abs(y));
}

inline IVector2D operator+(const IVector2D& vector1, const IVector2D& vector2) {
    return IVector2D(vector1.x + vector2.x, vector1.y + vector2.y);
}

inline IVector2D operator-(const IVector2D& vector1, const IVector2D&vector2) {
    return IVector2D(vector1.x - vector2.x, vector1.y - vector2.y);
}

inline IVector2D operator*(const IVector2D& vector1, const IVector2D& vector2) {
    return IVector2D(vector1.x* vector2.x, vector1.y* vector2.y);
}

inline IVector2D operator*(const IVector2D& vector, int value) {
    return IVector2D(vector.x * value, vector.y * value);
}

inline IVector2D operator*(int value, const IVector2D& vector) {
    return IVector2D(vector.x * value, vector.y * value);
}

inline IVector2D operator/(const IVector2D& vector1, const IVector2D& vector2) {
    return IVector2D(vector1.x / vector2.x, vector1.y / vector2.y);
}

inline IVector2D operator/(const IVector2D& vector, int value) {
    return IVector2D(vector.x / value, vector.y / value);
}

inline IVector2D operator/(int value, const IVector2D& vector) {
    return IVector2D(value / vector.x, value / vector.y);
}

inline int operator&(const IVector2D& vector1, const IVector2D& vector2) {
    return vector1.x* vector2.x + vector1.y* vector2.y;
}
