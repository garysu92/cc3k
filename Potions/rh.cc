#include "rh.h"

#include "potion.h"
#include "../Entities/playablecharacter.h"

bool RH::visible = false;

Potion::Type Potion::getType() const{
    return Potion::RH;
}

void RH::setVisible() {
    visible = true;
}

void RH::applyEffect(PlayableCharacter *pc) const{
    pc->addPermanentEffects(10, 0, 0);
}
