#ifndef GAME_IMAP_H
#define GAME_IMAP_H

#include "IVector2D.h"
#include "Cell.h"

class IMap {
public:
    virtual int create() = 0;

    IVector2D getSize() const { return size; }

    CellType getCellType(const IVector2D position) const {
        if (position.x >= size.x || position.y >= size.y) {
            return BAD_TYPE;
        }

        return cells[position.x * size.y + position.y].getType();
    }
    void setCellType(const IVector2D position, const CellType type) {
        if (position.x >= size.x || position.y >= size.y) {
            return;
        }

        cells[position.x * size.y + position.y].setType(type);
    }

    int getIndividualID(const IVector2D position) const {
        if (position.x >= size.x || position.y >= size.y) {
            return -1;
        }

        return individualID[position.x * size.y + position.y];
    }
    void setIndividualID(const IVector2D position, const int id) {
        if (position.x >= size.x || position.y >= size.y) {
            return;
        }

        individualID[position.x * size.y + position.y] = id;
    }

protected:
    Cell* cells;
    int* individualID;

    IVector2D size;

    IMap() { }

    IMap(IVector2D size) : size(size) { }

    virtual ~IMap() { }
};


#endif //GAME_IMAP_H
