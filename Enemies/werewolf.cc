#include "werewolf.h"

#include "../Entities/enemy.h"
#include <string>

using namespace std;

Werewolf::Werewolf(): Enemy{30, 5, 120, 1, 'W'} {}

bool Werewolf::isHostile() { 
    return true; 
}

string Werewolf::getType() const {
    return "Werewolf (W)"
}
