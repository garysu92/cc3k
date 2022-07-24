#include "bd.h"

#include <memory>
#include <utility>
#include "potion.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/boostdefense.h"

bool BD::visible = false;

Potion::Type BD::getType() const{
    return Potion::BD;
}

void BD::setVisible() {
    visible = true;
}

void BD::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<BoostDefense>()));
}
