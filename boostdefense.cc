#include <algorithm>
#include "boostdefense.h"
#include "playablecharacter.h"

using namespace std;

BoostDefense::BoostDefense(PlayableCharacter *pc): TempEffect{pc, 0, 5} {}

int BoostDefense::getAttack() const {
    return max(0, attack + TempEffect::getAttack());
}

int BoostDefense::getDefense() const {
    return max(0, defense + TempEffect::getDefense());
}

int BoostDefense::getHP() const {
    return TempEffect::getHP();
}

void BoostDefense::setHP(int hp) {
    TempEffect::setHP(hp);
}