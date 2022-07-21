#include <memory>
#include "playablecharacter.h"
#include "enemy.h"
#include "item.h"
#include "cell.h"
using namespace std;

Cell::Cell(int x, int y, char sym) : x{x}, y{y}, symbolRep{sym}, pc{nullptr}, enemy{nullptr}, item{nullptr} {}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

PlayableCharacter *Cell::getPC() {
    return this->pc;
}

Enemy * Cell::getEnemy() {
    return this->enemy;
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

void Cell::setPC(PlayableCharacter *pc) {
    this->pc = pc;
}

void Cell::setEnemy(Enemy *enemy) {
    this->enemy = enemy;
}

void Cell::setItem(unique_ptr<Item> &item) {
    item = move(item);
}

void Cell::setsymbolRep(char sym) {
    symbolRep = sym;
}

void Cell::setStair() {
    isStair = true;
}

bool Cell::hasEnemy() {
    return enemy != nullptr;
}

bool Cell::hasPC() {
    return pc != nullptr;
}

bool Cell::hasItem() {
    return item != nullptr;
}
