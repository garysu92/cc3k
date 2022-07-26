#include <string>
#include "ph.h"
#include "potion.h"
#include "../Entities/playablecharacter.h"

using namespace std;

bool PH::visible = false;

string PH::getPotOutput() const {
    return "Poison Health (-10HP)";
}

Potion::Type PH::getType() const{
    return Potion::PH;
}


void PH::applyEffect(PlayableCharacter *pc) const{
    pc->addPermanentEffects(-10, 0, 0);
    visible = true;
}

bool PH::isVisible() const {
    return visible;
}
