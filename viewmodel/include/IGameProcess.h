// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEWMODEL_INCLUDE_IGAMEPROCESS_H_
#define VIEWMODEL_INCLUDE_IGAMEPROCESS_H_

#include <Map.h>
#include <IPopulation.h>
class IGameProcess {
 protected:
    int generationNumber;
    int* generation;
    Map* map;
    IPopulation* population;
    std::vector<Individual> individuals;
    IGameProcess() {}
    virtual void getNextGeneration() = 0;

};

#endif  // VIEWMODEL_INCLUDE_IGAMEPROCESS_H_
