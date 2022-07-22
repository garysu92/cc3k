#include <cmath>
#include <memory>
#include <string>
#include <iostream>
#include "playablecharacter.h"
#include "enemy.h"

using namespace std;

PlayableCharacter::PlayableCharacter(int atk, int def, int hp): curGold{0}, maxHP{hp}, hp{hp}, attack{atk}, defense{def}, hasCompass{false}, hasBarrierSuit{false} {}

string PlayableCharacter::getRace() const { 
    return ""; 
}

// What about when playchar has barrier suit?
// Also technically shouldnt sent to cout but rather a string which is taken by action bar
void PlayableCharacter::takeDmg(Enemy *enemy) {
    cout << "PC has " << this->getHP() << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * enemy->getAttack());
    setHP(max(0, this->getHP() - dmg));
    cout << "PC took " << dmg << " damage, now PC has " << this->getHP() << " hp remaining. " << endl;
}

void PlayableCharacter::dealDmg(unique_ptr<Enemy> &enemy) {
    enemy->takeDmg(this);
}

int PlayableCharacter::getAttack() const {
    return this->attack;
}

int PlayableCharacter::getDefense() const {
    return this->defense;
}

int PlayableCharacter::getHP() const {
    return this->hp;
}

void PlayableCharacter::setHP(int k) {
    if (k > this->maxHP || k < 0) {
        cerr << "Invalid HP set" << endl;
        return;
    }
    else {
        this->hp = k;
    }
}

bool PlayableCharacter::checkCompass() {
    return this->hasCompass;
}

bool PlayableCharacter::checkBarrierSuit() {
    return this->hasBarrierSuit;
}

void PlayableCharacter::giveCompass() {
    this->hasCompass = true;
}

void PlayableCharacter::giveBarrierSuit() {
    this->hasBarrierSuit = true;
}

PlayableCharacter::~PlayableCharacter() {}
