// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_VECTOR2D_H_
#define MODEL_INCLUDE_VECTOR2D_H_

#include <algorithm>

template<typename T>
class Vector2D {
 public:
    T x, y;

    Vector2D() { }
    explicit Vector2D(T value) : x(value), y(value) { }
    Vector2D(T x, T y) : x(x), y(y) { }

    void set(T x, T y);

    int operator==(const Vector2D & vector) const;
    Vector2D & operator=(const Vector2D & vector);
    Vector2D operator+() const;
    Vector2D operator-() const;
    Vector2D & operator+=(const Vector2D & vector);
    Vector2D & operator-=(const Vector2D & vector);
    Vector2D & operator*=(const Vector2D & vector);
    Vector2D & operator*=(T value);
    Vector2D & operator/=(const Vector2D & vector);
    Vector2D & operator/=(T value);
    T& operator[](int index);
    int operator!=(const Vector2D & vector) const;
    operator T*();
    operator const T*() const;

    T length() const;
    T lengthSquare() const;
    Vector2D & normalize();
    T maxLength() const;

    template<typename T1>
    friend Vector2D<T1> operator+(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2);

    template<typename T1>
    friend Vector2D<T1> operator-(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2);

    template<typename T1>
    friend Vector2D<T1> operator*(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2);

    template<typename T1>
    friend Vector2D<T1> operator*(T value, const Vector2D<T1> & vector);

    template<typename T1>
    friend Vector2D<T1> operator*(const Vector2D<T1> &vector, T value);

    template<typename T1>
    friend Vector2D<T1> operator/(const Vector2D<T1> &vector, T value);

    template<typename T1>
    friend Vector2D<T1> operator/(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2);

    template<typename T1>
    friend T dot(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2);

    ~Vector2D() { }
};

typedef Vector2D<int> Vector2i;
typedef Vector2D<float> Vector2f;

template<typename T>
void Vector2D<T>::set(T x, T y) {
    this->x = x;
    this->y = y;
}

template<typename T>
int Vector2D<T>::operator==(const Vector2D<T> &vector) const {
    return (x == vector.x) && (y == vector.y);
}

template<typename T>
Vector2D<T>& Vector2D<T>::operator=(const Vector2D<T> &vector) {
    x = vector.x;
    y = vector.y;

    return *this;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator+() const {
    return *this;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator-() const {
    return Vector2D(-x, -y);
}

template<typename T>
Vector2D<T>& Vector2D<T>::operator+=(const Vector2D<T> &vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::operator-=(const Vector2D<T> &vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::operator*=(const Vector2D<T> &vector) {
    x *= vector.x;
    y *= vector.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::operator*=(T value) {
    x *= value;
    y *= value;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::operator/=(const Vector2D<T> &vector) {
    x /= vector.x;
    y /= vector.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::operator/=(T value) {
    x /= value;
    y /= value;

    return *this;
}

template<typename T>
T& Vector2D<T>::operator[](int index) {
    return *(index + &x);
}

template<typename T>
int Vector2D<T>::operator!=(const Vector2D<T> & vector) const {
    return x != vector.x || y != vector.y;
}

template<typename T>
Vector2D<T>::operator T*() {
    return &x;
}

template<typename T>
Vector2D<T>::operator const T*() const {
    return &x;
}

template<typename T>
T Vector2D<T>::length() const {
    return static_cast<T>(sqrt(x*x + y*y));
}

template<typename T>
T Vector2D<T>::lengthSquare() const {
    return x * x + y * y;
}

template<typename T>
Vector2D<T> &Vector2D<T>::normalize() {
    return (*this) /= length();
}

template<typename T>
T Vector2D<T>::maxLength() const {
    return std::max(abs(x), abs(y));
}

template<typename T1>
inline Vector2D<T1> operator+(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2) {
    return Vector2D<T1>(vector1.x + vector2.x, vector1.y + vector2.y);
}

template<typename T1>
inline Vector2D<T1> operator-(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2) {
    return Vector2D<T1>(vector1.x - vector2.x, vector1.y - vector2.y);
}

template<typename T1>
inline Vector2D<T1> operator*(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2) {
    return Vector2D<T1>(vector1.x* vector2.x, vector1.y* vector2.y);
}

template<typename T1>
inline Vector2D<T1> operator*(const Vector2D<T1> &vector, T1 value) {
    return Vector2D<T1>(vector.x * value, vector.y * value);
}

template<typename T1>
inline Vector2D<T1> operator*(T1 value, const Vector2D<T1> &vector) {
    return Vector2D<T1>(vector.x * value, vector.y * value);
}

template<typename T1>
inline Vector2D<T1> operator/(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2) {
    return Vector2D<T1>(vector1.x / vector2.x, vector1.y / vector2.y);
}

template<typename T1>
inline Vector2D<T1> operator/(const Vector2D<T1> &vector, T1 value) {
    return Vector2D<T1>(vector.x / value, vector.y / value);
}

template<typename T1>
inline Vector2D<T1> operator/(T1 value, const Vector2D<T1> &vector) {
    return Vector2D<T1>(value / vector.x, value / vector.y);
}

template<typename T1>
inline T1 dot(const Vector2D<T1> &vector1, const Vector2D<T1> &vector2) {
    return vector1.x* vector2.x + vector1.y* vector2.y;
}

#endif  // MODEL_INCLUDE_VECTOR2D_H_
