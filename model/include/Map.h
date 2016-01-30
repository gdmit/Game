#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "IMap.h"

class Map : public IMap {
public:
    Map() : IMap(IVector2D(0, 0)) { }
    Map(IVector2D size);

    virtual int create();

    virtual ~Map() { }
};

#endif //GAME_MAP_H
