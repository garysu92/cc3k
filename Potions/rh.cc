#include <string>
#include "rh.h"
#include "potion.h"
#include "../Entities/playablecharacter.h"

using namespace std;

bool RH::visible = false;

string RH::getPotType() const {
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
