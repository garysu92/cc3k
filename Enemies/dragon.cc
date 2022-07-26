#include <string>
#include "dragon.h"
#include "../Entities/enemy.h"
#include "../posn.h"

using namespace std;

Dragon::Dragon(int x, int y): Enemy{20, 20, 150, 0, 'D', true, false}, protectLocation{x, y} {}

bool Dragon::isHostile() { 
    return true; 
}

string Dragon::getType() const {
    return "Dragon (D)";
}

Posn Dragon::getProtect() {
    return protectLocation;
}

/*void Dragon::enemyAttack(PlayableCharacter *pc) {
    if 
}*/
