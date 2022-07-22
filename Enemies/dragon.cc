#include "dragon.h"

using namespace std;

Dragon::Dragon(): Enemy{20, 20, 150, 0} {}

bool Dragon::isHostile() { 
    return true; 
}
