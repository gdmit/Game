// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_GAMEPROCESS_H
#define MODEL_INCLUDE_GAMEPROCESS_H

#include "../../viewmodel/include/IGameProcess.h"

class GameProcess : public IGameProcess {
 public:
    GameProcess();
    explicit GameProcess(Vector2i mapSize);
    virtual void getNextGeneration();
    virtual int getMapHeight();
    virtual int getMapWidth();
    virtual Vector2i getMapSize();
    virtual void fillMapWithRandomPopulations(unsigned int seed);
    virtual void setMapCell(int col, int row, int populationID);
    virtual void updateGeneration();
};

#endif  // MODEL_INCLUDE_GAMEPROCESS_H
