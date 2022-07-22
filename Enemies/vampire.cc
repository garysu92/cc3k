#include "vampire.h"

using namespace std;

Vampire::Vampire(): Enemy{25, 25, 50, 1, 'V'} {}

bool Vampire::isHostile() { 
    return true; 
}
