#include "treasure.h"
#include "../Entities/playablecharacter.h"

Treasure::Treasure(int amount): sym{'G'}, amount{amount}, isPickedUp{false} {}

Treasure::~Treasure() {}

int Treasure::getAmount(){
    if (!isPickedUp) {
        isPickedUp = true;
        return amount;
    }
    return 0;
}

char Treasure::getSymbol() {
    return sym;
}

