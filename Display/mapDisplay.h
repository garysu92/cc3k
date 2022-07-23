#ifndef MAPDISPLAY_H
#define MAPDISPLAY_h

#include "cell.h"

class Mapdisplay {
    std::vector<std::vector<std::unique_ptr<Cell>>> map;
    
    public:
        Mapdisplay(std::vector<std::vector<std::unique_ptr<Cell>>> newFloor);
        printMap();
};

#endif
