#include "cell.h"
#include "stair.h"

Stair::Stair(int x, int y) : Cell{x, y, '.', false, true} {}

bool Stair::getVisibility() {
    return this->isVisible;
}

void Stair::setVisibility() {
    this->isVisible = true;
    if (this->isVisible) {
        this->setsymbolRep('\\');
    }
}
