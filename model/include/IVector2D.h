// Copyright (c) 2016 Evolution Team. All rights reserved.
#ifndef MODEL_INCLUDE_IVECTOR2D_H_
#define MODEL_INCLUDE_IVECTOR2D_H_

class IVector2D {
 public:
    static IVector2D zero;
    static IVector2D one;

    int x, y;

    IVector2D() { }
    explicit IVector2D(int value) : x(value), y(value) { }
    IVector2D(int x, int y) : x(x), y(y) { }
    explicit IVector2D(const IVector2D& vector) : x(vector.x), y(vector.y) { }

    void set(int x, int y);

    int operator==(const IVector2D& vector) const;
    IVector2D& operator=(const IVector2D& vector);
    IVector2D operator+() const;
    IVector2D operator-() const;
    IVector2D& operator+=(const IVector2D& vector);
    IVector2D& operator-=(const IVector2D& vector);
    IVector2D& operator*=(const IVector2D& vector);
    IVector2D& operator*=(int value);
    IVector2D& operator/=(const IVector2D& vector);
    IVector2D& operator/=(int value);
    int& operator[](int index);
    int operator!=(const IVector2D& vector) const;
    operator int*();
    operator const int*() const;

    float length() const;
    float lengthSquare() const;
    IVector2D& normalize();
    int maxLength() const;

    friend IVector2D operator+(const IVector2D& vector1,
                               const IVector2D& vector2);
    friend IVector2D operator-(const IVector2D& vector1,
                               const IVector2D& vector2);
    friend IVector2D operator*(const IVector2D& vector1,
                               const IVector2D& vector2);
    friend IVector2D operator*(int value, const IVector2D& vector);
    friend IVector2D operator*(const IVector2D& vector, int value);
    friend IVector2D operator/(const IVector2D& vector, int value);
    friend IVector2D operator/(const IVector2D& vector1,
                               const IVector2D& vector2);
    friend int operator&(const IVector2D& vector1, const IVector2D& vector2);
};

#endif  // MODEL_INCLUDE_IVECTOR2D_H_
