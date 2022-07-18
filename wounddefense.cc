#include "wounddefense.h"
#include "playablecharacter.h"

using namespace std;

WoundDefense::WoundDefense(PlayableCharacter *pc): TempEffect{pc, 0, -5} {}

int WoundDefense::getAttack() const {
    return -5 + TempEffect::getAttack();
}

int WoundDefense::getDefense() const {
    return TempEffect::getDefense();
}