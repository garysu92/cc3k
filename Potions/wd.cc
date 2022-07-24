#include "wd.h"

bool WD::visible = false;

Potion::Type Potion::getType() const{
    return Potion::WD;
}

void WD::setVisible() {
    visible = true;
}
