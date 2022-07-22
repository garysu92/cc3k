#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "dungeon.h"
#include "floor.h"

using namespace std;


// maybe make static function of class
static bool endOfRoom(string s) {
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] != '-') {
            return false;
        }
    }
    return true;
}

// constructor makes numFloors number of floors with same layout
Dungeon::Dungeon(PlayableCharacter *p, int numFloors) : fileName{floorLayout}, p{p}, curFloor{1}, numFloors{numFloors} {
    vector<vector<char>> v;
    try{
        ifstream file{fileName};
        /*file >> noskipws;
        
        while(!file.eof()) {
            v.emplace_back();
            char c = '\0';
            file >> c;
            while (c != '\n') {
                v.at(v.size() - 1).emplace_back(c);
            }
        }*/
        while (true) {
            string s = "";
            getline(file, s);
            if (s != "") {
                v.emplace_back();
                for (int i = 0; i < s.length(); i++) {
                    v.at(v.size() - 1).emplace_back(s[i]);
                }
            } else {
                // empty line, break
                break;
            }
        }

        file.close();
    } catch(...){
    }
    // loop 5 times to read in 5 potential different floor designs
    for (int q = 0; q < numFloors; q++) {
        // loop 25 times to read the 25 lines
        /*for (int r = 0; r < 25; r++) {
            // loop 79 times to read the 79 columns
            for (int t = 0; t < 79; t++) {
                file >> c;
                v[r].emplace_back(c);
            }
            v.emplace_back();
        }*/
        floors.emplace_back(v, p);
    }
}

// specified layout
Dungeon::Dungeon(string fileName, PlayableCharacter *p, bool save) : 
    fileName{fileName}, p{p}, curFloor{1}, numFloors{1}{
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

}

void Dungeon::playerAttack(Direction d) {
    
}

void Dungeon::playerUsePotion(Direction d) {
    
}
