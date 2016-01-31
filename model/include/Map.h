// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_MAP_H_
#define MODEL_INCLUDE_MAP_H_

#include "../include/IMap.h"

class Map : public IMap {
 public:
    Map() : IMap(IVector2D(0, 0)) { }
    explicit Map(IVector2D size);

    virtual int create();

    virtual ~Map() { }
};

#endif  // MODEL_INCLUDE_MAP_H_
