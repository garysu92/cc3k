#include <memory>
#include <utility>
#include <string>
#include "potion.h"
#include "wd.h"
#include "../Entities/playablecharacter.h"
#include "../TempEffects/tempeffect.h"
#include "../TempEffects/wounddefense.h"

using namespace std;

bool WD::visible = false;

string WD::getPotOutput() const {
    return "Wound Defense (-5Def)";
}

Potion::Type WD::getType() const{
    return Potion::WD;
}


void WD::applyEffect(PlayableCharacter *pc) const {
    pc->addTempEffect(std::move(std::make_unique<WoundDefense>()));
    visible = true;
}

bool WD::isVisible() const  {
    return visible;
}
