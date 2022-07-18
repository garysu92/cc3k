#include <cmath>
#include "enemy.h"
#include "playablecharacter.h"
#include <iostream>

using namespace std;

Enemy::Enemy(int atk, int def, int hp, int n): attack{atk}, defense{def}, hp{hp}, goldDrop{n} {}

int Enemy::goldDropped() {
    return goldDrop;
}

bool Enemy::isHostile() { return true; }

void Enemy::takeDmg(PlayableCharacter *pc) {
    cout << "playerchar has " << hp << " hp ";
    int dmg = ceil((100.0 / (100.0 + defense)) * pc->getAttack());
    hp = max(0, hp - dmg);
    cout << "playerchar took " << dmg << " damage. now, he has " << hp << " hp" << endl;
}

void Enemy::dealDmg(PlayableCharacter *pc) {
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

void Enemy::giveCompass() {
    compass = true;
}

Enemy::~Enemy() {}