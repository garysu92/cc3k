#ifndef STAIR_H
#define STAIR_H

#include "cell.h"

class Stair : public Cell {
    bool isVisible = false;

    public:
        Stair(int x, int y);
        bool getVisibility();
        void setVisibility(bool isVisible);
};

#endif
