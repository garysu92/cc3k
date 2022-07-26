#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include <vector>

class Cell;

class Mapdisplay {
    std::vector<std::vector<Cell *>> gameMap; // Noting that these are const ptrs within the same floor
    bool dm;
    public:
        Mapdisplay(std::vector<std::vector<std::unique_ptr<Cell>>> & newFloor, bool dm);
        void printMap();
};

#endif
