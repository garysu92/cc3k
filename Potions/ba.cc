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

string BA::getPotType() const {
    return "Boost Attack (+5Atk)";
}

Potion::Type BA::getType() const{
    return Potion::BA;
}

void BA::setVisible() {
    visible = true;
}

void BA::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<BoostAttack>()));
}
