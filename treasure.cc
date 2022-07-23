#include "treasure.h"

Treasure::Treasure(int amount): sym{'G'}, amount{amount} {}

Treasure::~Treasure() {}

char Treasure::getSymbol() {
    return sym;
}