#include "potion.h"

Potion::Potion(): sym{'P'} {}

Potion::~Potion() {}

char Potion::getSymbol() {
    return sym;
}