#include "ph.h"

#include "potion.h"
#include "../Entities/playablecharacter.h"

bool PH::visible = false;

Potion::Type Potion::getType() const{
    return Potion::PH;
}

void PH::setVisible() {
    visible = true;
}

void PH::applyEffect(PlayableCharacter *pc) const{
    pc->addPermanentEffects(-10, 0, 0);
}
