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
    position = convertToModelCoordinates(position);
    return individualID[position.y * size.x + position.x];
}

int Map::getIndividualID(int col, int row) const {
    Vector2i position = convertToModelCoordinates(Vector2i(col, row));
    return individualID[position.y * size.x + position.x];
}

void Map::setIndividualID(Vector2D<int> position, const int id) {
    position = convertToModelCoordinates(position);
    individualID[position.y * size.x + position.x] = id;
}

void Map::setIndividualID(int col, int row, const int id) {
    Vector2i position = convertToModelCoordinates(Vector2i(col, row));
    individualID[position.y * size.x + position.x] = id;
}

Vector2i Map::convertToModelCoordinates(Vector2i position) const {
    Vector2i coordinates = position;

    if (position.y < 0) {
        coordinates.y = size.y + position.y;
    }
    if (position.x < 0) {
        coordinates.x = size.x + position.x;
    }
    if (position.y >= size.y) {
        coordinates.y = position.y % size.y;
    }
    if (position.x >= size.x) {
        coordinates.x = position.x % size.x;
    }

    return coordinates;
}