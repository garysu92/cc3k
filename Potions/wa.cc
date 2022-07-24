#include "wa.h"

#include <memory>
#include <utility>
#include "potion.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/woundattack.h"

bool WA::visible = false;

Potion::Type Potion::getType() const{
    return Potion::WA;
}

void WA::setVisible() {
    visible = true;
}

void WA::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<WoundAttack>()));
}
