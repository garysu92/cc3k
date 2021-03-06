#include <memory>
#include <utility>
#include <string>
#include "potion.h"
#include "ba.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/boostattack.h"

using namespace std;

bool BA::visible = false;

string BA::getPotOutput() const {
    return "Boost Attack (+5Atk)";
}

Potion::Type BA::getType() const{
    return Potion::BA;
}


void BA::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<BoostAttack>()));
    visible = true;
}

bool BA::isVisible() const {
    return visible;
}
