#include <algorithm>
#include "boostattack.h"
#include "playablecharacter.h"

using namespace std;

BoostAttack::BoostAttack(PlayableCharacter *pc): TempEffect{pc, 5, 0} {}

int BoostAttack::getAttack() const {
    return max(0, attack + TempEffect::getAttack());
}

int BoostAttack::getDefense() const {
    return max(0, defense + TempEffect::getDefense());
}

int BoostAttack::getHP() const {
    return TempEffect::getHP();
}

void BoostAttack::setHP(int hp) {
    TempEffect::setHP(hp);
}