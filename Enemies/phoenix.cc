#include <string>
#include "phoenix.h"

using namespace std;

Phoenix::Phoenix(): Enemy{35, 20, 50, 1, 'X'} {}

bool Phoenix::isHostile() { 
    return true; 
}

string Phoenix::getType() const {
    return "Phoenix (X)";
}
