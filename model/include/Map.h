// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_MAP_H_
#define MODEL_INCLUDE_MAP_H_

#include "../include/IMap.h"

class Map : public IMap {
 public:
    explicit Map(Vector2i size);

    virtual int create();

    virtual Vector2i getSize() const;
    virtual CellType getCellType(const Vector2D<int> position) const;
    virtual void setCellType(const Vector2D<int> position, const CellType type);

    virtual int getIndividualID(Vector2D<int> position) const;
    virtual int getIndividualID(int row, int col) const;
    virtual  void setIndividualID(Vector2D<int> position, const int id);

    virtual ~Map();
};

#endif  // MODEL_INCLUDE_MAP_H_
