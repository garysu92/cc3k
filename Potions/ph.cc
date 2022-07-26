#include <string>
#include "ph.h"
#include "potion.h"
#include "../Entities/playablecharacter.h"

bool PH::visible = false;

string getPotType() const {
    return "Poison Health (-10HP)";
}

Potion::Type PH::getType() const{
    return Potion::PH;
}

void PH::setVisible() {
    visible = true;
}

void PH::applyEffect(PlayableCharacter *pc) const{
    pc->addPermanentEffects(-10, 0, 0);
}
