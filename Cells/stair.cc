#include "cell.h"
#include "stair.h"

Stair::Stair() : Cell{'.', false, true} {}

bool Stair::getVisibility() {
    return this->isVisible;
}

void Stair::setVisibility() {
    this->isVisible = true;
    if (this->isVisible) {
        this->setsymbolRep('\\');
    }
}
