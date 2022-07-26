#include <cmath>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include "playablecharacter.h"
#include "enemy.h"
#include "../TempEffects/tempeffect.h"

using namespace std;

PlayableCharacter::PlayableCharacter(int atk, int def, int hp): curGold{0}, maxHP{hp}, hp{hp}, 
                                                                attack{atk}, defense{def}, 
                                                                hasCompass{false}, hasBarrierSuit{false}, cellConnection{nullptr}, dead{false}, tempEffects{}, curAction{""} {}

string PlayableCharacter::getRace() const { 
    return ""; 
}

// Also technically shouldnt sent to cout but rather a string which is taken by action bar
void PlayableCharacter::takeDmg(Enemy *enemy) {
    //cout << "PC currently has " << this->getHP() << " hp. ";
    int dmg = ceil((100.0 / (100.0 + getDefense())) * enemy->getAttack());
    if (this->hasBarrierSuit) {
        dmg = ceil(dmg/2);
    }
    setHP(max(0, this->getHP() - dmg));
    if (this->getHP() == 0) {
        this->setDead(true);                // Set PCs state to Dead
        //Cell * curPcell = this->getCell();  // Find the Cell PC is standing on
        //curPcell->setPC(nullptr);           // Set the ptr from Cell to PC to nullptr, as PC is no longer is alive
        //cout << "PC took " << dmg << " damage, now PC is Dead." << endl;;
    } //else {
        //cout << "PC took " << dmg << " damage, now PC has " << this->getHP() << " hp remaining. " << endl;
    //}
}

int PlayableCharacter::getAttack() const {
    int atk = attack;
    for (int i = 0; i < tempEffects.size(); i++) {
        atk += tempEffects.at(i)->getAttackEffect();
    }

    return max(0, atk);
}

int PlayableCharacter::getDefense() const {
    int def = defense;
    for (int i = 0; i < tempEffects.size(); i++) {
        def += tempEffects.at(i)->getDefenseEffect();
    }

    return max(0, def);
}

int PlayableCharacter::getHP() const {
    return this->hp;
}

float PlayableCharacter::getcurGold() const {
    return this->curGold;
}

 int PlayableCharacter::getMaxHP() const {
    return this->maxHP;
 }

 Cell * PlayableCharacter::getCell() const {
    return this->cellConnection;
 }

bool PlayableCharacter::getDead() const {
    return this->dead;
}

string PlayableCharacter::getcurAction() const {
    return this->curAction;
}

 void PlayableCharacter::setCell(Cell * newCell) {
    this->cellConnection = newCell;
 }

 void PlayableCharacter::setDead(bool dead) {
    if (dead and !this->dead) {
        this->curAction = this->curAction + "PC has died. ";
    }
    this->dead = dead;
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

void PlayableCharacter::setcurAction(string curAction) {
    this->curAction = curAction;
}

bool PlayableCharacter::checkCompass() {
    return this->hasCompass;
}

bool PlayableCharacter::checkBarrierSuit() {
    return this->hasBarrierSuit;
}

void PlayableCharacter::setCompass(bool hasCompass) {
    this->hasCompass = hasCompass;
    if (hasCompass) {
        this->curAction = this->curAction + "PC picked up the Compass, the stairs to the next floor are now visible. Look for the \\ symbol on the map. "; 
    }
}

void PlayableCharacter::setBarrierSuit(bool hasBarrierSuit) {
    this->hasBarrierSuit = hasBarrierSuit;
    if (hasBarrierSuit) {
        this->curAction = this->curAction + "PC picked up the Barrier Suit, and now feels stronger. "; 
    }
}

void PlayableCharacter::usePotion(Potion *p) {
    p->potionGetUsed(this);
    this->curAction = this->curAction + "PC used a " + p->getPotType() + " potion. ";
}

void PlayableCharacter::removeTempEffects() {
    tempEffects.clear();
}

void PlayableCharacter::addTempEffect(unique_ptr<TempEffect> t) {
    tempEffects.emplace_back(move(t));
}

void PlayableCharacter::addPermanentEffects(int hp, int atk, int def) {
    this->hp += hp;
    attack += atk;
    defense += def;
    if (attack < 0) {
        attack = 0;
    }
    if (defense < 0) {
        defense = 0;
    }
    if (this->hp < 0) {
        this->hp = 0;
    } else if (this->hp > maxHP){
        this->hp = maxHP;
    }
}

void PlayableCharacter::attackEnemy(Enemy *em) {
    int curHP = em->getHP();
    em->getAttackedByPlayer(this);
    int newHP = em->getHP();
    if (newHP > 0) {
        this->curAction = this->curAction + "PC deals " + to_string(curHP - newHP) + " damage to " + em->getType() + " and it has " + to_string(newHP) + " hp left. ";
    }
    else {
        this->curAction = this->curAction + "PC deals " + to_string(curHP - newHP) + " damage to " + em->getType() + " and kills it. ";
    }
}

void PlayableCharacter::getAttackedByEnemy(Enemy *em) {
    int curHP = this->getHP();
    takeDmg(em);
    int newHP = this->getHP();
    if (newHP > 0) {
        this->curAction = this->curAction + em->getType() + " deals " + to_string(curHP - newHP) + " damage to PC. ";
    }
}  

void PlayableCharacter::getDroppedGold(Enemy *em) {
    int oldGold = this->curGold;
    int gold = em->goldDropped();
    addGold(gold);
    int newGold = this->curGold;
    this->curAction = this->curAction + "PC picked up " + to_string(newGold - oldGold) + " gold. ";
}

void PlayableCharacter::addGold(int gold) {
    curGold += gold;
}

void PlayableCharacter::pickupTreasure(Treasure *t) {
    int oldGold = this->curGold;
    int gold = t->getAmount();
    addGold(gold);
    int newGold = this->curGold;
    this->curAction = this->curAction + "PC picked up " + to_string(newGold - oldGold) + " gold. ";
}

PlayableCharacter::~PlayableCharacter() {}
