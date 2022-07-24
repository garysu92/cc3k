#include "bd.h"

bool BD::visible = false;

Potion::Type Potion::getType() const{
    return Potion::BD;
}

void BD::setVisible() {
    visible = true;
}

void BD::applyEffect(PlayableCharacter *pc) const{
    
}
