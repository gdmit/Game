// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_INDIVIDUAL_H_
#define MODEL_INCLUDE_INDIVIDUAL_H_

#include "../include/IVector2D.h"

class Individual {
 private:
    IVector2D position;

 public:
    IVector2D getPosition() const {
        return position;
    }

    void setPosition(const IVector2D position) {
        this->position = position;
    }

    Individual(const IVector2D position = IVector2D(0, 0)) :
        position(position) { }
};


#endif  // MODEL_INCLUDE_INDIVIDUAL_H_
