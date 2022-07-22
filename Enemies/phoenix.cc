#include "phoenix.h"

using namespace std;

Phoenix::Phoenix(): Enemy{35, 20, 50, 1} {}

bool Phoenix::isHostile() { 
    return true; 
}
