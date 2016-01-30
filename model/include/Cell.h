#ifndef GAME_CELL_H
#define GAME_CELL_H

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
    Cell(CellType type = PLAINS) : type(type) { }

    CellType getType() const;

    void setType(const CellType type);

    virtual ~Cell() { }
};


#endif //GAME_CELL_H
