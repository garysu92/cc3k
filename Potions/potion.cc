#include <utility>
#include "potion.h"
#include "../Entities/playablecharacter.h"

using namespace std;

Potion::Potion(): sym{'P'}, used{false} {}

Potion::~Potion() {}

char Potion::getSymbol() {
    return sym;
}

void Potion::potionGetUsed(PlayableCharacter *pc) {
    if (!used) {
        applyEffect(pc);
        used = true;
    }
}

bool Potion::isVisible() const  {
    return false;
}

std::string Potion::getPotType() const {
    if (isVisible()) {
        return "Unknown potion";
    } else {
        return this->getPotOutput();
    }
}
