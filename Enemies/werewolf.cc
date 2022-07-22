#include "werewolf.h"

using namespace std;

Werewolf::Werewolf(): Enemy{30, 5, 120, 1, 'W'} {}

bool Werewolf::isHostile() { 
    return true; 
}
