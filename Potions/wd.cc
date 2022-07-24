#include "wd.h"

#include <memory>
#include <utility>
#include "potion.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/wounddefense.h"

bool WD::visible = false;

Potion::Type Potion::getType() const{
    return Potion::WD;
}

void WD::setVisible() {
    visible = true;
}

void WD::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<WoundDefense>()));
}
