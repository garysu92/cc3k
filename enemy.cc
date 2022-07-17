#include <cmath>
#include "enemy.h"
#include "playablecharacter.h"
#include <iostream>

using namespace std;

Enemy::Enemy(int atk, int def, int hp, int n): Entity{atk, def, hp}, goldDrop{n} {}

int Enemy::goldDropped() {
    return goldDrop;
}

bool Enemy::isHostile() { return true; }

Enemy::~Enemy() {}