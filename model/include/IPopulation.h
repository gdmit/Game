// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_IPOPULATION_H_
#define MODEL_INCLUDE_IPOPULATION_H_

#include "../include/Individual.h"
#include "../include/IMap.h"
#include <vector>

class IPopulation {
 public:
    virtual int getIndividualsCount() const = 0;
    virtual void nextGeneration() = 0;
    virtual void updatePopulation() = 0;
    virtual ~IPopulation() { }
 protected:
    int ID;
    std::vector<Individual>* individuals;
    IMap *map;

    IPopulation(int ID, std::vector<Individual> *individuals, IMap *map) : ID(ID), individuals(individuals), map(map) {}

    virtual void addIndividual(Individual &individual) = 0;
    virtual void deleteIndividual(int individualNumber) = 0;

};



#endif  // MODEL_INCLUDE_IPOPULATION_H_
