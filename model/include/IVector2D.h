#ifndef GAME_VECTOR2D_H
#define GAME_VECTOR2D_H
#include <math.h>
#include <stdlib.h>

class IVector2D {
public:
    static IVector2D zero;
    static IVector2D one;

    int x, y;

    IVector2D() { }
    IVector2D(int value) : x(value), y(value) { }
    IVector2D(int x, int y) : x(x), y(y) { }
    IVector2D(const IVector2D& vector) : x(vector.x), y(vector.y) { }

    void set(int, int);

    int operator==(const IVector2D&) const;
    IVector2D& operator=(const IVector2D&);
    IVector2D operator+() const;
    IVector2D operator-() const;
    IVector2D& operator+=(const IVector2D&);
    IVector2D& operator-=(const IVector2D&);
    IVector2D& operator*=(const IVector2D&);
    IVector2D& operator*=(int);
    IVector2D& operator/=(const IVector2D&);
    IVector2D& operator/=(int);
    int& operator[](int);
    int	operator!=(const IVector2D&) const;
    operator int*();
    operator const int*() const;

    float length() const;
    float lengthSquare() const;
    IVector2D& normalize();
    int maxLength() const;

    friend IVector2D operator+(const IVector2D&, const IVector2D&);
    friend IVector2D operator-(const IVector2D&, const IVector2D&);
    friend IVector2D operator*(const IVector2D&, const IVector2D&);
    friend IVector2D operator*(int, const IVector2D&);
    friend IVector2D operator*(const IVector2D&, int);
    friend IVector2D operator/(const IVector2D&, int);
    friend IVector2D operator/(const IVector2D&, const IVector2D&);
    friend int operator&(const IVector2D&, const IVector2D&);
private:
    int max(int a, int b) const;
    int min(int a, int b) const;
    int sqr(int x) const;
};

#endif //GAME_VECTOR2D_H
