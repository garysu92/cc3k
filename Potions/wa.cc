#include <memory>
#include <utility>
#include <string>
#include "potion.h"
#include "wa.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/woundattack.h"

bool WA::visible = false;

string getPotType() const {
    return "Wound Attack (-5Atk)"
}

Potion::Type WA::getType() const{
    return Potion::WA;
}

void WA::setVisible() {
    visible = true;
}

void WA::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<WoundAttack>()));
}
