#include "dragon.h"

using namespace std;

Dragon::Dragon(int x, int y): Enemy{20, 20, 150, 0, 'D'}, protectLocation{x, y} {}

bool Dragon::isHostile() { 
    return true; 
}
