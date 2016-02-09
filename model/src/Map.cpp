// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../include/Map.h"

int Map::create() {
    return 0;
}

Map::Map(IVector2D size) : IMap(size) {
    cells = new Cell[size.x * size.y];

    individualID = new int[size.x * size.y];
    for (int i = 0; i < size.x * size.y; i++) {
        individualID[i] = 0;
    }
}

Map::~Map() {
    delete []individualID;
    delete []cells;
}