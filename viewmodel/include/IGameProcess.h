// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef VIEWMODEL_INCLUDE_IGAMEPROCESS_H_
#define VIEWMODEL_INCLUDE_IGAMEPROCESS_H_

#include <../../model/include/IPopulation.h>
#include <../../model/include/Map.h>
class IGameProcess {
 protected:
    int generationNumber;
    Map* map;
    IPopulation* population;
    std::vector<Individual> individuals;
    IGameProcess() {}
 public:
    int* generation;
    virtual void getNextGeneration() = 0;
    virtual int getMapHeight() = 0;
    virtual int getMapWidth() = 0;
    virtual Vector2i getMapSize() = 0;
};

#endif  // VIEWMODEL_INCLUDE_IGAMEPROCESS_H_
