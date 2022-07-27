#include "enemy.h"
#include "playablecharacter.h"
#include <cmath>
#include <string>
#include <iostream>
#include <memory>
#include <random>
#include <chrono>
#include <utility>
#include <algorithm>
#include "../Cells/cell.h"
#include "../posn.h"
#include "../randnum.h"

using namespace std;

Enemy::Enemy(int atk, int def, int hp, int n, char symbol, bool isDragon, bool isMerchant):  goldDrop{n}, hp{hp},
         attack{atk}, defense{def}, hasCompass{false}, symbol{symbol}, drag{isDragon}, merch{isMerchant}, hasDroppedGold{false} {}

/*int Enemy::goldDropped() {
    return this->goldDrop;
}*/

bool Enemy::isHostile() { 
    return true; 
}

// What about when playchar has barrier suit?
// Also technically shouldnt sent to cout but rather a string which is taken by action bar, and should change for every subclass rather than couting "enemy has"
void Enemy::takeDmg(PlayableCharacter *pc) {
    //cout << "Enemy has " << this->hp << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * pc->getAttack());
    this->hp = max(0, hp - dmg); // Use setter instead?
    //cout << "Enemy took " << dmg << " damage, now Enemy has " << this->getHP() << " hp remaining. " << endl; 
}

/*void Enemy::dealDmg(PlayableCharacter *pc) {
    int miss = randNum() % 2;
    if (!miss) pc->takeDmg(this);
}*/

int Enemy::getAttack() const {
    return this->attack;
}

int Enemy::getDefense() const {
    return this->defense;
}

int Enemy::getHP() const {
    return this->hp;
}

char Enemy::getSymbol() const {
    return symbol;
}

bool Enemy::checkCompass() {
    return this->hasCompass;
}

bool Enemy::isDragon() const {
    return drag;
}

bool Enemy::isMerchant() const {
    return merch;
}

string Enemy::getType() const { 
    return ""; 
}

void Enemy::giveCompass() {
    this->hasCompass = true;
}

void Enemy::dropCompass() {
    this->hasCompass = false;
}

void Enemy::attackPlayer(PlayableCharacter *pc) {
    int miss = randNum() % 2;
    if (!miss && isHostile()) {
        enemyAttack(pc);
    }
    else {
        pc->appendcurAction(this->getType() + " tried to attack PC but missed. ");     
    }
}

void Enemy::enemyAttack(PlayableCharacter *pc) {
    pc->getAttackedByEnemy(this);
}

void Enemy::getAttackedByPlayer(PlayableCharacter *pc) {
    // calculate damage 
    takeDmg(pc);
    if (isDead() && !hasDroppedGold && !drag) {
        deathProcedure();
        pc->getDroppedGold(this);
        hasDroppedGold = true;
    }
}

/*void Enemy::dropGold(PlayableCharacter *pc) {
    if (isDead() && !hasDroppedGold) {
        pc->getDroppedGold(this);
    }
}*/

// returns the amount of gold that this enemy would drop in its
// current state
int Enemy::goldDropped() const {
    if (isDead() && !hasDroppedGold) {
        return goldDrop;
    }
    return 0;
}

bool Enemy::isDead() const{
    return hp == 0;
}

void Enemy::deathProcedure() {}

Posn Enemy::getProtect() {
    return Posn{-1,-1};
}

Enemy::~Enemy() {}
