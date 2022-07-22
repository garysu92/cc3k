#include <utility>
#include "cell.h"

class PlayableCharacter;
class Enemy;
class Item;

using namespace std;

Cell::Cell(int x, int y, char sym, bool isEffWall, bool isStair) : x{x}, y{y}, pc{nullptr}, enemy{nullptr}, item{nullptr},  symbolRep{sym}, isEffWall{isEffWall}, isStair{false} {}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

PlayableCharacter *Cell::getPC() {
    return this->pc;
}

Enemy *Cell::getEnemy() {
    return this->enemy;
}

Item *Cell::getItem() {
    return this->item;
}

char Cell::getsymbolRep() {
    return this->symbolRep;
}

bool Cell::getisEffWall() {
    return this->isEffWall;
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

void Cell::setItem(Item *item) {
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

void Cell::setisEffWall(bool isEffWall) {
    this->isEffWall = isEffWall;
}
