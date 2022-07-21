#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "dungeon.h"
#include "floor.h"

using namespace std;

Dungeon::Dungeon(string fileName, PlayableCharacter *p, int curFloor, int numFloors) : fileName{fileName}, p{p}, curFloor{curFloor}, numFloors{numFloors} {
    ifstream file;
    char c;
    char count = 0;
    // loop 5 times to read in 5 potential different floor designs
    for (int q = 0; q < numFloors; q++) {
        vector<vector<char>> v;
        v.emplace_back();
        // loop 25 times to read the 25 lines
        for (int r = 0; r < 25; r++) {
            // loop 79 times to read the 79 columns
            for (int t = 0; t < 79; t++) {
                file >> c;
                v[r].emplace_back(c);
            }
            v.emplace_back();
        }
        // calls floor ctor
        floors.emplace_back(v, p);
    }
    file.close();
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
