#include <memory>
#include <utility>
#include <string>
#include "potion.h"
#include "wa.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/woundattack.h"

using namespace std;

bool WA::visible = false;

string WA::getPotOutput() const {
    return "Wound Attack (-5Atk)";
}

Potion::Type WA::getType() const{
    return Potion::WA;
}


void WA::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<WoundAttack>()));
    visible = true;
}

bool WA::isVisible() const {
    return visible;
}
