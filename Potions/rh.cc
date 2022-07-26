#include <string>
#include "rh.h"
#include "potion.h"
#include "../Entities/playablecharacter.h"

bool RH::visible = false;

string getPotType() const {
    return "Poison Health (-10HP)";
}

Potion::Type RH::getType() const{
    return Potion::RH;
}

void RH::setVisible() {
    visible = true;
}

void RH::applyEffect(PlayableCharacter *pc) const{
    pc->addPermanentEffects(10, 0, 0);
}
