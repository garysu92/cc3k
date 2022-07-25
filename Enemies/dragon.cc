#include <string>
#include "dragon.h"
#include "../posn.h"

using namespace std;

Dragon::Dragon(int x, int y): Enemy{20, 20, 150, 0, 'D', true}, protectLocation{x, y} {}

bool Dragon::isHostile() { 
    return true; 
}

std::string getType() const {
    return "Dragon (D)";
}

Posn Dragon::getProtect() {
    return protectLocation;
}

/*void Dragon::enemyAttack(PlayableCharacter *pc) {
    if 
}*/
