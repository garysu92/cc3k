#include "goblin.h"
#include "../Entities/enemy.h"
#include <string>

using namespace std;

Goblin::Goblin(): Enemy{5, 10, 70, 1, 'N'} {}

bool Goblin::isHostile() { 
    return true;
}

std::string Goblin::getType() const {
    return "Goblin (N)";
}
