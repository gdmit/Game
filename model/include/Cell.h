// Copyright (c) 2016 Evolution Team. All rights reserved.

#ifndef MODEL_INCLUDE_CELL_H_
#define MODEL_INCLUDE_CELL_H_

enum CellType {
    BAD_TYPE,
    PLAINS,
    MOUNTAIN,
    WATER,
    FOREST,
    DESERT,
    SWAMPLAND,
    ICELAND
};

class Cell {
 private:
    CellType type;

 public:
    explicit Cell(CellType type = PLAINS) : type(type) { }

    CellType getType() const;

    void setType(const CellType type);

    virtual ~Cell() { }
};


#endif  // MODEL_INCLUDE_CELL_H_
