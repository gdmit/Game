// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_POPULATION_H_
#define MODEL_INCLUDE_POPULATION_H_

#include "../include/IPopulation.h"

class Population : public IPopulation {
 public:
    Population(int ID, std::vector<Individual> *individuals, IMap *map);
    virtual void nextGeneration();
    virtual void updatePopulation();
    virtual void updateMap() const;
    virtual Individual& getIndividual(int index);

    virtual int getIndividualsCount() const;
    virtual void addIndividual(Individual individual);
    virtual void deleteIndividual(int individualNumber);
    virtual ~Population();
 private:
};

#endif  // MODEL_INCLUDE_POPULATION_H_
