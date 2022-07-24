#include "wa.h"

bool WA::visible = false;

Potion::Type Potion::getType() const{
    return Potion::WA;
}

void WA::setVisible() {
    visible = true;
}
