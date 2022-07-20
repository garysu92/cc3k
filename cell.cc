#include <memory>
#include "playablecharacter.h"
#include "enemy.h"
// #include "item.h"
#include "cell.h"
using namespace std;

Cell::Cell(int x, int y, char sym) : x{x}, y{y}, symbolRep{sym};

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

PlayableCharacter * Cell::getPC() {
    return this->PC;
}

Enemy * Cell::getEnemy() {
    return this->foe;
}

// Item * Cell::getItem() {
//     return this->onFloor;
// }

char Cell::getsymbolRep() {
    return this->symbolRep;
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

void Cell::setPC(PlayableCharacter * PC) {
    this->PC = PC;
}

void Cell::setEnemy(Enemy * foe) {
    this->foe = foe;
}

// void Cell::setItem(Item * onFloor) {
//     this->onFloor = onFloor;
// }

void Cell::setsymbolRep(char sym) {
    this->symbolRep = sym;
}
