#include <string>
#include <algorithm>

#include "merchant.h"
#include "../Entities/enemy.h"

using namespace std;

bool Merchant::hostile = false;

Merchant::Merchant(): Enemy{70, 5, 30, 0, 'M', false, true} {}

bool Merchant::isHostile() {
    return hostile;
}

void Merchant::takeDmg(PlayableCharacter *pc) {
    hostile = true;
    Enemy::takeDmg(pc);
}

std::string Merchant::getType() const {
    return "Merchant (M)";
}
