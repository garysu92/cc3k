#include <utility>

#include "potion.h"
#include "../Entities/playablecharacter.h"


using namespace std;

Potion::Potion(): sym{'P'} {}

Potion::~Potion() {}

char Potion::getSymbol() {
    return sym;
}

void Potion::potionGetUsed(PlayableCharacter *pc) {
    applyEffect(pc);
}
