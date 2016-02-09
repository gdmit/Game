// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_IPOPULATION_H_
#define MODEL_INCLUDE_IPOPULATION_H_

#include "../include/Individual.h"
#include <vector>

class IPopulation {
 protected:
    int ID;
    int individualsCount;
    std::vector<Individual>* individuals;

    IPopulation(int ID, int individualsCount) :
        ID(ID), individualsCount(individualsCount) { }

 public:
    virtual ~IPopulation() { }
};

#endif  // MODEL_INCLUDE_IPOPULATION_H_
