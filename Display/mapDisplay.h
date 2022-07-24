#ifndef MAPDISPLAY_H
#define MAPDISPLAY_h

#include <vector>
#include "../Cells/cell.h"

class Mapdisplay {
    std::vector<std::vector<Cell *>> gameMap; // Noting that these are const ptrs within the same floor
    
    public:
        Mapdisplay(std::vector<std::vector<std::unique_ptr<Cell>>> & newFloor);
        void printMap();
};

#endif
