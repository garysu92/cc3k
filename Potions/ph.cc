#include "ph.h"

bool PH::visible = false;

Potion::Type Potion::getType() const{
    return Potion::PH;
}

void PH::setVisible() {
    visible = true;
}

void PH::applyEffect(PlayableCharacter *pc) const{
    
}
