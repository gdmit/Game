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

    return cells[position.x * size.y + position.y].getType();
}
void Map::setCellType(const Vector2D<int> position, const CellType type) {
    if (position.x >= size.x || position.y >= size.y) {
        return;
    }

    cells[position.x * size.y + position.y].setType(type);
}

int Map::getIndividualID(Vector2i position) const {
    if (position.x < 0) {
        position.x = size.x + position.x;
    }
    if (position.y < 0) {
        position.y = size.y + position.y;
    }
    if (position.x >= size.x) {
        position.x = position.x % size.x;
    }
    if (position.y >= size.y) {
        position.y = position.y % size.y;
    }
    return individualID[position.x * size.y + position.y];
}

int Map::getIndividualID(int row, int col) const {
    if (row < 0) {
        row = size.x + row;
    }
    if (col < 0) {
        col = size.y + col;
    }
    if (row >= size.x) {
        row = row % size.x;
    }
    if (col >= size.y) {
        col = col % size.y;
    }
    return individualID[row * size.y + col];
}

void Map::setIndividualID(Vector2D<int> position, const int id) {
    if (position.x < 0) {
        position.x = size.x + position.x;
    }
    if (position.y < 0) {
        position.y = size.y + position.y;
    }
    if (position.x >= size.x) {
        position.x = position.x % size.x;
    }
    if (position.y >= size.y) {
        position.y = position.y % size.y;
    }
    individualID[position.x * size.y + position.y] = id;
}

