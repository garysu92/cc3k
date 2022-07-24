#include "potion.h"
#include "Entities/playablecharacter.h"

Potion::Potion(): sym{'P'} {}

Potion::~Potion() {}

char Potion::getSymbol() {
    return sym;
}

void Potion::applyEffect(PlayableCharacter *pc) const{

}
