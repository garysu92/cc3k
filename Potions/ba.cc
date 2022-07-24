#include "ba.h"

#include <memory>
#include <utility>
#include "potion.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/boostattack.h"

bool BA::visible = false;

Potion::Type Potion::getType() const{
    return Potion::BA;
}

void BA::setVisible() {
    visible = true;
}

void BA::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<BoostAttack>()));
}
