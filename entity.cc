#include <cmath>
#include <algorithm>
#include <iostream>
#include "entity.h"

using namespace std;

Entity::Entity(int atk, int def, int hp): attack{atk}, defense{def}, maxHP{hp}, hp{hp} {}

int Entity::getAttack() const {
    return attack;
}
    
int Entity::getDefense() const {
    return defense;
}

int Entity::getHP() const {
    return hp;
}

void Entity::takeDmg(Entity *entity) {
    cout << "playerchar has " << hp << " hp";
    int dmg = ceil((100.0 / (100.0 + defense)) * entity->getAttack());
    hp = max(0, hp - dmg);
    cout << "playerchar took " << dmg << " damage. now, he has " << hp << " hp" << endl;
}

void Entity::dealDmg(Entity *entity) {
    entity->takeDmg(this);
}

int Entity::getMaxHP() const {
    return maxHP;
}

Entity::~Entity() {}