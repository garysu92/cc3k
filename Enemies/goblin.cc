#include <string>
#include "goblin.h"

using namespace std;

Goblin::Goblin(): Enemy{5, 10, 70, 1, 'N'} {}

bool Goblin::isHostile() { 
    return true;
}

string Goblin::getType() const {
    return "Goblin (N)";
}
