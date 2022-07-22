#include "cell.h"
#include "stair.h"

Stair::Stair(int x, int y) : Cell{x, y, '.', false, true} {}

bool Stair::getVisibility() {
    return this->isVisible;
}

void Stair::setVisibility(bool isVisible) {
    this->isVisible = isVisible;
    if (this->isVisible) {
        this->setsymbolRep('\\');
    }
}
