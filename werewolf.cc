#include "werewolf.h"

using namespace std;

Werewolf::Werewolf(): Enemy{30, 5, 120, 1} {}

bool Werewolf::isHostile() { return true; }
