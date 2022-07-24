#include "rh.h"

bool RH::visible = false;

Potion::Type Potion::getType() const{
    return Potion::RH;
}

void RH::setVisible() {
    visible = true;
}
