#ifndef WALL_H
#define WALL_H

#include "cell.h"

class Wall : public Cell {
    public:
        Wall(int x, int y, char sym);
};

#endif
