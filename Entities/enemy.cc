#include "enemy.h"
#include "playablecharacter.h"
#include <cmath>
#include <iostream>
#include <memory>

using namespace std;

Enemy::Enemy(int atk, int def, int hp, int n):  goldDrop{n}, hp{hp}, attack{atk}, defense{def} {}

int Enemy::goldDropped() {
    return this->goldDrop;
}

bool Enemy::isHostile() { 
    return true; 
}

// What about when playchar has barrier suit?
// Also technically shouldnt sent to cout but rather a string which is taken by action bar, and should change for every subclass rather than couting "enemy has"
void Enemy::takeDmg(PlayableCharacter *pc) {
    cout << "Enemy has " << this->hp << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * pc->getAttack());
    this->hp = max(0, hp - dmg); // Use setter instead?
    cout << "Enemy took " << dmg << " damage, now Enemy has " << this->getHP() << " hp remaining. " << endl;
}

void Enemy::dealDmg(unique_ptr<PlayableCharacter> &pc) {
    pc->takeDmg(this);
}

int Enemy::getAttack() const {
    return attack;
}

int Enemy::getDefense() const {
    return defense;
}

int Enemy::getHP() const {
    return hp;
}

bool Enemy::hasCompass() {
    return compass;
}

void Enemy::giveCompass() {
    compass = true;
}

void Enemy::dropCompass() {
    compass = false;
}

Enemy::~Enemy() {}
