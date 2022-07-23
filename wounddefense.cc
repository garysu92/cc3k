#include <algorithm>
#include <memory>
#include "wounddefense.h"
#include "Entities/playablecharacter.h"

using namespace std;

WoundDefense::WoundDefense(shared_ptr<PlayableCharacter> pc): TempEffect{pc, 0, -5} {}

int WoundDefense::getAttack() const {
    return max(0, attack + TempEffect::getAttack());
}

int WoundDefense::getDefense() const {
    return max(0, defense + TempEffect::getDefense());
}

int WoundDefense::getHP() const {
    return TempEffect::getHP();
}

void WoundDefense::setHP(int hp) {
    TempEffect::setHP(hp);
}

/*
WoundDefense::~WoundDefense() {
    TempEffect::~TempEffect();
}
*/
