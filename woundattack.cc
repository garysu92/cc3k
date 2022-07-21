#include <algorithm>
#include <memory>
#include "woundattack.h"
#include "playablecharacter.h"

using namespace std;

WoundAttack::WoundAttack(unique_ptr<PlayableCharacter> pc): TempEffect{move(pc), -5, 0} {}

int WoundAttack::getAttack() const {
    return max(0, attack + TempEffect::getAttack());
}

int WoundAttack::getDefense() const {
    return max(0, defense + TempEffect::getDefense());
}

int WoundAttack::getHP() const {
    return TempEffect::getHP();
}

void WoundAttack::setHP(int hp) {
    TempEffect::setHP(hp);
}

/*
WoundAttack::~WoundAttack() {
    TempEffect::~TempEffect();
}
*/
