#include <cmath>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "playablecharacter.h"
#include "enemy.h"
#include "../TempEffects/tempeffect.h"

using namespace std;

PlayableCharacter::PlayableCharacter(int atk, int def, int hp): curGold{0}, maxHP{hp}, hp{hp}, 
                                                                attack{atk}, defense{def}, 
                                                                hasCompass{false}, hasBarrierSuit{false},
                                                                tempEffects{} {}

string PlayableCharacter::getRace() const { 
    return ""; 
}

// What about when playchar has barrier suit?
// Also technically shouldnt sent to cout but rather a string which is taken by action bar
void PlayableCharacter::takeDmg(Enemy *enemy) {
    cout << "PC currently has " << this->getHP() << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * enemy->getAttack());
    if (this->hasBarrierSuit) {
        dmg = ceil(dmg/2);
    }
    setHP(max(0, this->getHP() - dmg));
    if (this->getHP() == 0) {
        this->setState(true);               // Set PCs state to Dead
        Cell * curPcell = this->getCell();  // Find the Cell PC is standing on
        curPcell->setPC(nullptr);           // Set the ptr from Cell to PC to nullptr, as PC is no longer is alive
        cout << "PC took " << dmg << " damage, now PC is Dead.";
    } else {
        cout << "PC took " << dmg << " damage, now PC has " << this->getHP() << " hp remaining. " << endl;
    }
}

void PlayableCharacter::dealDmg(Enemy *e) {
    e->takeDmg(this);
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

 int PlayableCharacter::getMaxHP() const {
    return this->maxHP;
 }

 Cell * PlayableCharacter::getCell() const {
    return this->cellConnection;
 }

bool PlayableCharacter::getState() const {
    return this->isDead;
}

 void PlayableCharacter::setCell(Cell * newCell) {
    this->cellConnection = newCell;
 }

 void PlayableCharacter::setState(bool alive) {
    this->isDead = alive;
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

void PlayableCharacter::usePotion(Potion *p) {
    p->applyEffect(this);
}

void PlayableCharacter::removeTempEffects() {

}

PlayableCharacter::~PlayableCharacter() {}
