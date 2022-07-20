#include <string>
#include "dungeon.h"

using namespace std;

Dungeon::Dungeon(string fileName, int curFloor, int numFloors) : fileName{fileName}, curFloor{curFloor}, numFloors{numFloors} {}

int Dungeon::get_curFloor() {
    return this->curFloor;
}

int Dungeon::get_numFloors() {
    return this->numFloors;
}

void Dungeon::set_curFloor(int curF) {
    this->curFloor = curF;
}

void Dungeon::set_curFloor(int newF) {
    this->curFloor = newF;
}
