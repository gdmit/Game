// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_VECTOR3D_H_
#define MODEL_INCLUDE_VECTOR3D_H_

#include <algorithm>

template<typename T>
class Vector3D {
 public:
    T x, y, z;
    Vector3D() { }
    explicit Vector3D(T value) : x(value), y(value), z(value) { }
    Vector3D(T x, T y, T z) : x(x), y(y), z(z) { }

    int operator==(const Vector3D & vector) const;
    Vector3D & operator=(const Vector3D & vector);
    Vector3D operator+() const;
    Vector3D operator-() const;
    Vector3D & operator+=(const Vector3D & vector);
    Vector3D & operator-=(const Vector3D & vector);
    Vector3D & operator*=(const Vector3D & vector);
    Vector3D & operator*=(T value);
    Vector3D & operator/=(const Vector3D & vector);
    Vector3D & operator/=(T value);
    T& operator[](int index);
    int operator!=(const Vector3D & vector) const;

    operator T*();
    operator const T*() const;

    T length() const;
    T lengthSquare() const;
    Vector3D & normalize();
    T maxLength() const;

    template<typename T1>
    friend Vector3D<T1> operator+(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2);

    template<typename T1>
    friend Vector3D<T1> operator-(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2);

    template<typename T1>
    friend Vector3D<T1> operator*(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2);

    template<typename T1>
    friend Vector3D<T1> operator*(T value, const Vector3D<T1> & vector);

    template<typename T1>
    friend Vector3D<T1> operator*(const Vector3D<T1> &vector, T value);

    template<typename T1>
    friend Vector3D<T1> operator/(const Vector3D<T1> &vector, T value);

    template<typename T1>
    friend Vector3D<T1> operator/(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2);

    template<typename T1>
    friend T dot(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2);

    ~Vector3D() { }
};

template<typename T>
int Vector3D<T>::operator==(const Vector3D<T> &vector) const {
    return (x == vector.x) && (y == vector.y) && (z == vector.z);
}

template<typename T>
Vector3D<T>& Vector3D<T>::operator=(const Vector3D<T> &vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;

    return *this;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator+() const {
    return *this;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator-() const {
    return Vector3D(-x, -y, -z);
}

template<typename T>
Vector3D<T>& Vector3D<T>::operator+=(const Vector3D<T> &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    
    return *this;
}

template<typename T>
Vector3D<T>& Vector3D<T>::operator-=(const Vector3D<T> &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}

template<typename T>
Vector3D<T>& Vector3D<T>::operator*=(const Vector3D<T> &vector) {
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
    
    return *this;
}

template<typename T>
Vector3D<T>& Vector3D<T>::operator*=(T value) {
    x *= value;
    y *= value;
    z *= value;
    
    return *this;
}

template<typename T>
Vector3D<T>& Vector3D<T>::operator/=(const Vector3D<T> &vector) {
    x /= vector.x;
    y /= vector.y;
    z /= vector.z;
    
    return *this;
}

template<typename T>
Vector3D<T>& Vector3D<T>::operator/=(T value) {
    x /= value;
    y /= value;
    z /= value;

    return *this;
}

template<typename T>
T& Vector3D<T>::operator[](int index) {
    return *(index + &x);
}

template<typename T>
int Vector3D<T>::operator!=(const Vector3D<T> & vector) const {
    return x != vector.x || y != vector.y || z != vector.z;
}

template<typename T>
Vector3D<T>::operator T*() {
    return &x;
}

template<typename T>
Vector3D<T>::operator const T*() const {
    return &x;
}


template<typename T>
T Vector3D<T>::length() const {
    return static_cast<T>(sqrt(x * x + y * y + z * z));
}

template<typename T>
T Vector3D<T>::lengthSquare() const {
    return x * x + y * y + z * z;
}

template<typename T>
Vector3D<T> &Vector3D<T>::normalize() {
    return (*this) /= length();
}

template<typename T>
T Vector3D<T>::maxLength() const {
    return std::max(abs(x), abs(y), abs(z));
}

template<typename T1>
inline Vector3D<T1> operator+(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2) {
    return Vector3D<T1>(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z);
}

template<typename T1>
inline Vector3D<T1> operator-(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2) {
    return Vector3D<T1>(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
}

template<typename T1>
inline Vector3D<T1> operator*(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2) {
    return Vector3D<T1>(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z);
}

template<typename T1>
inline Vector3D<T1> operator*(const Vector3D<T1> &vector, T1 value) {
    return Vector3D<T1>(vector.x * value, vector.y * value, vector.z * value);
}

template<typename T1>
inline Vector3D<T1> operator*(T1 value, const Vector3D<T1> &vector) {
    return Vector3D<T1>(vector.x * value, vector.y * value, vector.z * value);
}

template<typename T1>
inline Vector3D<T1> operator/(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2) {
    return Vector3D<T1>(vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z);
}

template<typename T1>
inline Vector3D<T1> operator/(const Vector3D<T1> &vector, T1 value) {
    return Vector3D<T1>(vector.x / value, vector.y / value, vector.z / value);
}

template<typename T1>
inline Vector3D<T1> operator/(T1 value, const Vector3D<T1> &vector) {
    return Vector3D<T1>(value / vector.x, value / vector.y, value / vector.y);
}

template<typename T1>
inline T1 dot(const Vector3D<T1> &vector1, const Vector3D<T1> &vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

#endif  // MODEL_INCLUDE_VECTOR3D_H_
