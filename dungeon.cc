#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "dungeon.h"
#include "floor.h"
#include "randnum.h"
#include "Cells/cell.h"
#include "Display/mapDisplay.h"
#include "Display/actionDisplay.h"

using namespace std;

extern const string floorLayout;

std::vector<std::vector<std::unique_ptr<Cell>>> & Dungeon::get_floorContents() {
    return floors[curFloor].getContents();
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

// Constructor which makes numFloors floors with same layout for each
Dungeon::Dungeon(PlayableCharacter *p, int numFloors) : fileName{floorLayout}, curFloor{1}, numFloors{numFloors}, p{p}, curMap{}, curActionBar{} {
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
    this->curMap = make_unique<Mapdisplay>(this->get_floorContents());
    this->curActionBar = make_unique<Actiondisplay>(this->p);
}

// Constructor which makes floors with a file specified layout
Dungeon::Dungeon(string fileName, PlayableCharacter *p, bool save) : 
    fileName{fileName}, curFloor{1}, numFloors{1}, p{p}, curMap{}, curActionBar{} {
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

    this->curMap = make_unique<Mapdisplay>(this->get_floorContents());
    this->curActionBar = make_unique<Actiondisplay>(this->p);
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

void Dungeon::set_numFloors(int newF) {
    this->numFloors = newF;
}

void Dungeon::playerMove(Direction d) {
    cerr << "Moving player " << endl;
    floors[curFloor].movePC(d);
    cerr << "Player moved succesffuly " << endl;
    cerr << "Moving enemies " << endl;
    floors[curFloor].updateEnemies();
    cerr << "Enemies moved succesffuly " << endl;
    cerr << "Printing map Display" << endl;
    (this->curMap)->printMap();
    cerr << "Map display printed sucessfully" << endl;
    (this->curActionBar)->printActionDisplay();
}

void Dungeon::playerAttack(Direction d) {
    floors[curFloor].attack(d);
    floors[curFloor].updateEnemies();
    (this->curMap)->printMap();
    (this->curActionBar)->printActionDisplay();
}

void Dungeon::playerUsePotion(Direction d) {
    //floors[curFloor].usePotion(d);
    floors[curFloor].updateEnemies();
    (this->curMap)->printMap();
    (this->curActionBar)->printActionDisplay();
}
