#include "treasure.h"

Treasure::Treasure(int amount, bool dh): sym{'G'}, amount{amount}, isPickedUp{false}, dh{dh} {}

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

bool Treasure::isDragonHoarde() {
    return dh;
}
