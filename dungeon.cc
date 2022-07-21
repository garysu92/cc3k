#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "dungeon.h"
#include "floor.h"

using namespace std;

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
            vector<vector<char>>
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
