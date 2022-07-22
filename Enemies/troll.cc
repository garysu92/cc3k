#include "troll.h"

using namespace std;

Troll::Troll(): Enemy{25, 15, 120, 1, 'T'} {}

bool Troll::isHostile() { 
    return true; 
}
