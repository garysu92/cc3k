#include <memory>
#include "playablecharacter.h"
#include "enemy.h"
// #include "item.h"
#include "cell.h"
using namespace std;

Cell::Cell(int x, int y) : x{x}, y{y}; // All other fields are initalized within the subclasses

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

unique_ptr<PlayableCharacter> Cell::getPC() {
    return this->PC;
}

unique_ptr<Enemy> Cell::getEnemy() {
    return this->foe;
}

// unique_ptr<Item> Cell::getItem() {
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


// Setters
        void setX(int x);
        void setY(int y)
        void setPC(std::unique_ptr<PlayableCharacter> PC);
        void setEnemy(std::unique_ptr<Enemy> foe);
        // void setItem(std::unique_ptr<Item> onFloor);
        void setsymbolRep(char sym);