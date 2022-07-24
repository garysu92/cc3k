#include "ba.h"

bool BA::visible = false;

Potion::Type Potion::getType() const{
    return Potion::BA;
}

void BA::setVisible() {
    visible = true;
}
void BA::applyEffect(PlayableCharacter *pc) const{
    
}
