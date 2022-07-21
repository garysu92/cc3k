#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "dungeon.h"

using namespace std;

Dungeon::Dungeon(string fileName, int curFloor, int numFloors) : fileName{fileName}, curFloor{curFloor}, numFloors{numFloors} {
    ofstream file;
    vector<vector<char>> v;
    v.emplace_back();
    
    // REMEMBER to catch potential erros
}

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
