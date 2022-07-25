#include <utility>
#include <memory>
#include "cell.h"
#include "../Potions/potion.h"
#include "../Treasure/treasure.h"
#include "../Entities/enemy.h"

class PlayableCharacter;

using namespace std;

Cell::Cell(int x, int y, char sym, bool isEffWall, bool isStair) : x{x}, y{y}, pc{nullptr}, enemy{nullptr}, potion{}, treasure{}, symbolRep{sym}, isEffWall{isEffWall}, isStair{false} {}

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

unique_ptr<Potion> &Cell::getPotion() {
    return this->potion;
}

unique_ptr<Treasure> &Cell::getTreasure() {
    return this->treasure;
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

void Cell::setPotion(unique_ptr<Potion> &potion) {
    this->potion = std::move(potion);
}

void Cell::setTreasure(unique_ptr<Treasure> &treasure) {
    this->treasure = std::move(treasure);
}

void Cell::setsymbolRep(char sym) {
    symbolRep = sym;
}

void Cell::setStair() {
    isStair = true;
}

void Cell::setBarrierSuit(bool b) {
    bs = b;
}

bool Cell::hasEnemy() {
    return enemy != nullptr;
}

bool Cell::hasPC() {
    return pc != nullptr;
}

bool Cell::hasPotion() {
    return potion != nullptr;
}

bool Cell::hasTreasure() {
    return treasure != nullptr;
}

bool Cell::hasBarrierSuit() {
    return bs;
}

bool Cell::hasCompass() {
    return comp;
}

bool Cell::getVisibility() {
    return true;
}

void Cell::setCompass(bool b) {
    comp = b;
}
void Cell::setVisibility() {}

void Cell::setisEffWall(bool isEffWall) {
    this->isEffWall = isEffWall;
}

void Cell::clear() {
    if (hasPC()) pc = nullptr;
    if (hasEnemy()) enemy = nullptr;
    if (hasPotion()) potion.reset();
    if (hasTreasure()) treasure.reset();
}
