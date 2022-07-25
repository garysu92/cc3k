#include <string>
#include "vampire.h"

#include "../Entities/enemy.h"
#include <string>

using namespace std;

Vampire::Vampire(): Enemy{25, 25, 50, 1, 'V'} {}

bool Vampire::isHostile() { 
    return true; 
}

string Vampire::getType() const {
    return "Vampire (V)";
}
