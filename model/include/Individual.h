#ifndef GAME_INDIVIDUAL_H
#define GAME_INDIVIDUAL_H

#include "IVector2D.h"

class Individual {
    IVector2D position;

public:
    IVector2D getPosition() const {
        return position;
    }

    void setPosition(const IVector2D position) {
        this->position = position;
    }

    Individual(const IVector2D position = IVector2D(0, 0)) : position(position) { }
};


#endif //GAME_INDIVIDUAL_H
