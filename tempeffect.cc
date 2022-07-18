#include "tempeffect.h"
#include <iostream> 
using namespace std;

class PlayableCharacter;

TempEffect::TempEffect(PlayableCharacter *pc, int atkEffect, int defEffect): PlayableCharacter{atkEffect, defEffect, 0}, p{pc} {}

int TempEffect::getAttack() const {
    return p->getAttack();
}

int TempEffect::getDefense() const {
    //cout << "defense: " << defense << endl;
    //cout << "defense2: " << p->getDefense() << endl;
    return p->getDefense();
}

int TempEffect::getHP() const {
    return p->getHP();
}

void TempEffect::setHP(int k) {
    p->setHP(k);
}
