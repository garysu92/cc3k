#include <memory>
#include <utility>
#include <string>
#include "potion.h"
#include "bd.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/boostdefense.h"

using namespace std;

bool BD::visible = false;

string BD::getPotType() const {
    return "Boost Defense (+5Def)";
}

Potion::Type BD::getType() const{
    return Potion::BD;
}

void BD::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<BoostDefense>()));
    visible = true;
}

bool BD::isVisible() {
    return visible;
}
