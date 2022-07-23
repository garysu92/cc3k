#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "dungeon.h"
#include "floor.h"
#include "randnum.h"

using namespace std;

// Constructor which makes numFloors floors with same layout for each
Dungeon::Dungeon(shared_ptr<PlayableCharacter> p, int numFloors) : fileName{floorLayout}, p{p}, curFloor{1}, numFloors{numFloors} {
    floorWithBarrierSuit = randNum() % 5 + 1; // Is not actually used
    vector<vector<char>> v;
    try {
        ifstream file{fileName};
        while (true) {
            string s = "";
            getline(file, s);
            if (s != "") {
                v.emplace_back();
                for (int i = 0; i < s.length(); i++) {
                    v.at(v.size() - 1).emplace_back(s[i]);
                }
            } 
            else {
                // empty line, break
                break;
            }
        }

        file.close();
    } catch(...){
    }
    // loop 5 times to read in 5 potential different floor designs
    for (int q = 0; q < numFloors; q++) {
        floors.emplace_back(v, p);
    }
}

// Constructor which makes floors with a file specified layout
Dungeon::Dungeon(string fileName, shared_ptr<PlayableCharacter> p, bool save) : 
    fileName{fileName}, p{p}, curFloor{1}, numFloors{1} {
        try{
            fstream file{fileName};
            
            while (true) {
                string s = "";
                getline(file, s);
                if (s == "") {
                    break;
                }
                // new floor
                vector<vector<char>> v{};
                v.emplace_back();
                while(true){
                    for (int i = 0; i < s.length(); i++) {
                        v.at(v.size() - 1).emplace_back(s[i]);
                    }
                    getline(file, s);
                    if (endOfRoom(s)) {
                        break;
                    }
                }
                for (int i = 0; i < s.length(); i++) {
                        v.at(v.size() - 1).emplace_back(s[i]);
                }
                if (save) {
                    floors.emplace_back(v, p, true, true);
                } else {
                    floors.emplace_back(v, p, true, false);
                }
            }
            
        } catch (...) {}
        
}

// maybe make static function of class
static bool endOfRoom(string s) {
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] != '-') {
            return false;
        }
    }
    return true;
}

Floor * Dungeon::get_floor(int n) {
    if (n >= 1 && n <= this->get_numFloors()) {
        return &(floors.at(n));
    }
    else {
        cerr << "Error, Attempting to Get Invalid Floor." << endl;
    }
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

void Dungeon::playerMove(Direction d) {
    floors[curFloor].movePC();
}

void Dungeon::playerAttack(Direction d) {
    floors[curFloor].attack(d);
}

void Dungeon::playerUsePotion(Direction d) {
    floors[curFloor].usePotion(d);
}
