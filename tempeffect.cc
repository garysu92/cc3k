#include "tempeffect.h"

class PlayableCharacter;

TempEffect::TempEffect(PlayableCharacter *pc, int atkEffect, int defEffect): PlayableCharacter{atkEffect, defEffect, 0}, p{pc} {}

int TempEffect::getAttack() {
    return attack + p->getAttack();
}

int TempEffect::getDefense() {
    return defense + p->getDefense();
}
