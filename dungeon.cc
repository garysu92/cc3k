#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>
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
    return floors[curFloor - 1].getContents();
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
Dungeon::Dungeon(PlayableCharacter *p, bool dev, int numFloors) : fileName{floorLayout}, dev{dev}, curFloor{1}, numFloors{numFloors}, p{p}, curMap{}, curActionBar{} {
    floorWithBarrierSuit = randNum() % 5;
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

        for (int q = 0; q < numFloors; q++) {
            if (q == floorWithBarrierSuit) floors.emplace_back(v, p, true);
            else floors.emplace_back(v, p, false);
        }
        this->curMap = make_unique<Mapdisplay>(this->get_floorContents(), dev);
        this->curActionBar = make_unique<Actiondisplay>(this->p, curFloor);
        p->appendcurAction("PC has spawned. ");
    } catch (...) {
    }

}

// Constructor which makes floors with a file specified layout
Dungeon::Dungeon(string fileName, PlayableCharacter *p, bool dev, bool save) : 
    fileName{fileName}, curFloor{1}, numFloors{0}, p{p}, curMap{}, curActionBar{}, dev{dev} {
        try {
            cout << "start" << endl;
            ifstream file{fileName};
            while (true) {
                string s = "";
                getline(file, s);
                if (s == "") {
                    break;
                }
                // new floor
                vector<vector<char>> v;
                while(true){
                    v.emplace_back();
                    for (int i = 0; i < s.length(); i++) {
                        v.at(v.size() - 1).emplace_back(s[i]);
                    }
                    getline(file, s);
                    if (endOfRoom(s)) {
                        v.emplace_back();
                        for (int i = 0; i < s.length(); i++) {
                            v.at(v.size() - 1).emplace_back(s[i]);
                        }
                        break;
                    }
                }
                if (save) {
                    floors.emplace_back(v, p, true, true);
                } else {
                    cout << "floor" << endl;
                    floors.emplace_back(v, p, true, false);
                    cout << "floor" << endl;
                }
            }
            file.close();
            numFloors = floors.size();
            // NOTE, need to check for current floor in save
            cerr << "a" << endl;
            this->curMap = make_unique<Mapdisplay>(this->get_floorContents(), dev);
            cerr << "b" << endl;
            this->curActionBar = make_unique<Actiondisplay>(this->p, curFloor);
            cerr << "c" << endl;
            p->appendcurAction("PC has spawned. ");
        } catch (...) {}
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

void Dungeon::printGame() {
    (this->curMap)->printMap();
    (this->curActionBar)->printActionDisplay();
}

void Dungeon::playerMove(Direction d) {
    //cerr << "Moving player " << endl;
    floors[curFloor - 1].movePC(d);
    //cerr << "Player moved succesffuly " << endl;
    //cerr << "Moving enemies " << endl;
    //floors[curFloor - 1].updateEnemies();
    //cerr << "Enemies moved succesffuly " << endl;
    //cerr << "Printing Map and Action Display" << endl;
    this->printGame();
    postMoveCheck();
}

void Dungeon::playerAttack(Direction d) {
    floors[curFloor - 1].attack(d);
    //floors[curFloor - 1].updateEnemies();
    this->printGame();
    postMoveCheck();
}

void Dungeon::playerUsePotion(Direction d) {
    floors[curFloor - 1].usePotion(d);
    //floors[curFloor - 1].updateEnemies();
    this->printGame();
    postMoveCheck();
}

void Dungeon::postMoveCheck() {
    if (floors.at(curFloor - 1).PConStair()) {
        nextFloor();
    }
}

void Dungeon::nextFloor() {
    ++curFloor;
    if (!end()) {
        p->removeTempEffects();
        curActionBar = make_unique<Actiondisplay>(p, curFloor);
        curMap = make_unique<Mapdisplay>(get_floorContents(), dev);
        p->appendcurAction("PC has moved to Floor " + to_string(curFloor) + ". ");
        this->printGame();
    }
}

bool Dungeon::end() const{
    return curFloor > numFloors;
}
