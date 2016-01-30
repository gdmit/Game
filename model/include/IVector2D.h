#ifndef GAME_VECTOR2D_H
#define GAME_VECTOR2D_H

class IVector2D {
public:
    int x, y;

    IVector2D() { }

    IVector2D(int value) : x(value), y(value) { }

    IVector2D(int x, int y) : x(x), y(y) { }

    void set(int, int);

    int operator==(const IVector2D &vector) const;
};

#endif //GAME_VECTOR2D_H
