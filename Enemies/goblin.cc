#include "goblin.h"

using namespace std;

Goblin::Goblin(): Enemy{5, 10, 70, 1} {}

bool Goblin::isHostile() { 
    return true;
}
