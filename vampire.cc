#include "vampire.h"
// bruh
#icnlude "werewolf.h"

using namespace std;

Vampire::Vampire(): Enemy{25, 25, 50, 1} {}

bool Vampire::isHostile() { return true; }