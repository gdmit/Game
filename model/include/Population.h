// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_POPULATION_H_
#define MODEL_INCLUDE_POPULATION_H_

#include "../include/IPopulation.h"

class Population : public IPopulation {
 public:
    Population(int ID, int individualsCount);

    virtual ~Population();
};

#endif  // MODEL_INCLUDE_POPULATION_H_
