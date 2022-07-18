#include "woundattack.h"
#include "playablecharacter.h"

using namespace std;

WoundAttack::WoundAttack(PlayableCharacter *pc): TempEffect{pc, -5, 0} {}

int WoundAttack::getAttack() const {
    return -5 + TempEffect::getAttack();
}

int WoundAttack::getDefense() const {
    return TempEffect::getDefense();
}