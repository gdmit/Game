// Copyright (c) 2016 Evolution Team. All rights reserved.

#include "../include/Cell.h"

CellType Cell::getType() const {
    return type;
}

void Cell::setType(const CellType type) {
    this->type = type;
}
