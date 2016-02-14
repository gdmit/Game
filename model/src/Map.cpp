// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../include/Map.h"

int Map::create() {
    return 0;
}

Map::Map(Vector2i size) : IMap(size) {
    cells = new Cell[size.x * size.y];

    individualID = new int[size.x * size.y];
    for (int i = 0; i < size.x * size.y; i++) {
        individualID[i] = -1;
    }
}


Map::~Map() {
    delete []individualID;
    delete []cells;
}

Vector2i Map::getSize() const {
    return size;
}

CellType Map::getCellType(const Vector2D<int> position) const {
    if (position.x >= size.x || position.y >= size.y) {
        return BAD_TYPE;
    }

    return cells[position.y * size.x + position.x].getType();
}
void Map::setCellType(const Vector2D<int> position, const CellType type) {
    if (position.x >= size.x || position.y >= size.y) {
        return;
    }

    cells[position.y * size.x + position.x].setType(type);
}

int Map::getIndividualID(Vector2i position) const {
    if (position.y < 0) {
        position.y = size.y + position.y;
    }
    if (position.x < 0) {
        position.x = size.x + position.x;
    }
    if (position.y >= size.y) {
        position.y = position.y % size.y;
    }
    if (position.x >= size.x) {
        position.x = position.x % size.x;
    }
    return individualID[position.y * size.x + position.x];
}

int Map::getIndividualID(int col, int row) const {
    if (row < 0) {
        row = size.y + row;
    }
    if (col < 0) {
        col = size.x + col;
    }
    if (row >= size.y) {
        row = row % size.y;
    }
    if (col >= size.x) {
        col = col % size.x;
    }
    return individualID[row * size.x + col];
}

void Map::setIndividualID(Vector2D<int> position, const int id) {
    if (position.y < 0) {
        position.y = size.y + position.y;
    }
    if (position.x < 0) {
        position.x = size.x + position.x;
    }
    if (position.y >= size.y) {
        position.y = position.y % size.y;
    }
    if (position.x >= size.x) {
        position.x = position.x % size.x;
    }
    individualID[position.y * size.x + position.x] = id;
}

void Map::setIndividualID(int col, int row, const int id) {
    if (row < 0) {
        row = size.y + row;
    }
    if (col < 0) {
        col = size.x + col;
    }
    if (row >= size.y) {
        row = row % size.y;
    }
    if (col >= size.x) {
        col = col % size.x;
    }
    individualID[row * size.x + col] = id;
}
