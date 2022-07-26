#ifndef STAIR_H
#define STAIR_H

#include "cell.h"

class Stair : public Cell {
    bool isVisible = false;

    public:
        Stair();
        bool getVisibility() override;
        void setVisibility() override;
};

#endif
