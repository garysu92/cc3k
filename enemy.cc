#include <cmath>
#include "enemy.h"
#include "playablecharacter.h"
#include <iostream>
#include <memory>

using namespace std;

Enemy::Enemy(int atk, int def, int hp, int n):  goldDrop{n},hp{hp}, attack{atk}, defense{def}{}

int Enemy::goldDropped() {
    return goldDrop;
}

bool Enemy::isHostile() { return true; }

void Enemy::takeDmg(PlayableCharacter *pc) {
    cout << "playerchar has " << hp << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * pc->getAttack());
    hp = max(0, hp - dmg);
    cout << "playerchar took " << dmg << " damage. now, he has " << this->getHP() << " hp" << endl;
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
