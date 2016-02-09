// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_INDIVIDUAL_H_
#define MODEL_INCLUDE_INDIVIDUAL_H_

#include "Vector2D.h"

class Individual {
 private:
    Vector2i position;

 public:
    Individual(const Vector2i position = Vector2i(0, 0)) : position(position) { }
    Individual(const int row, const int col) : position(Vector2i(row, col)) { }

    Vector2i getPosition() const {
        return position;
    }

    void setPosition(const Vector2i position) {
        this->position = position;
    }

    virtual ~Individual() { }
};


#endif  // MODEL_INCLUDE_INDIVIDUAL_H_
