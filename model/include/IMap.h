// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_IMAP_H_
#define MODEL_INCLUDE_IMAP_H_

#include "Vector2D.h"
#include "../include/Cell.h"

class IMap {
 public:
    virtual int create() = 0;
    virtual Vector2i getSize() const = 0;

    virtual CellType getCellType(const Vector2D<int> position) const = 0;
    virtual void setCellType(const Vector2D<int> position, const CellType type) = 0;

    virtual int getIndividualID(Vector2D<int> position) const = 0;
    virtual int getIndividualID(int row, int col) const = 0;
    virtual  void setIndividualID(Vector2D<int> position, const int id) = 0;

 protected:
    Cell* cells;
    int* individualID;

    Vector2i size;

    IMap() {}

    explicit IMap(Vector2i size) : size(size) { }

    virtual ~IMap() { }
};


#endif  // MODEL_INCLUDE_IMAP_H_
