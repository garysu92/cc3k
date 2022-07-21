#include "stair.h"

Stair::Stair(int x, int y) : Cell{x, y, '.', false, true} {}

bool Stair::getVisibility() {
    return this->isVisible;
}

void Stair::setVisibilty(bool isVisibile) {
    this->isVisible = isVisible;
    if (this->isVisible) {
        this->setsymbolRep('\\');
    }
}
