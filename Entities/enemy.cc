#include "enemy.h"
#include "playablecharacter.h"
#include <cmath>
#include <iostream>
#include "../Cells/cell.h"
#include <memory>
#include <random>
#include <chrono>
#include <utility>
#include <algorithm>

using namespace std;

Enemy::Enemy(int atk, int def, int hp, int n, char symbol, bool isDragon):  goldDrop{n}, hp{hp}, attack{atk}, defense{def}, hasCompass{false}, symbol{symbol}, drag{isDragon} {}

int Enemy::goldDropped() {
    return this->goldDrop;
}

bool Enemy::isHostile() { 
    return true; 
}

static unsigned int randnum() {
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};

    vector<int> v{};

    for (int i = 0; i < 10000; i++) {
        v.emplace_back(i);
    }
    std::shuffle(v.begin(), v.end(), rng);
    return v[0];
}

// What about when playchar has barrier suit?
// Also technically shouldnt sent to cout but rather a string which is taken by action bar, and should change for every subclass rather than couting "enemy has"
void Enemy::takeDmg(PlayableCharacter *pc) {
    cout << "Enemy has " << this->hp << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * pc->getAttack());
    this->hp = max(0, hp - dmg); // Use setter instead?
    cout << "Enemy took " << dmg << " damage, now Enemy has " << this->getHP() << " hp remaining. " << endl; 
}

void Enemy::dealDmg(PlayableCharacter *pc) {
    int miss = randnum() % 2;
    if (!miss) pc->takeDmg(this);
}

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

bool Enemy::isDragon() {
    return isDragon;
}

bool Enemy::isMerchant() {
    return isMerchant;
}

void Enemy::giveCompass() {
    this->hasCompass = true;
}

void Enemy::dropCompass() {
    this->hasCompass = false;
}


Enemy::~Enemy() {}
