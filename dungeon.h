#ifndef DUNGEON_H
#define DUNGEON_H

#include <memory>
#include <vector>
#include <string>

#include "floor.h"
#include "direction.h"

std::string floorLayout = "cc3kfloor.txt";

class Dungeon {
    string fileName;
    std::vector<Floor> floors; 
    int curFloor;
    int numFloors;
    int floorWithBarrierSuit;
    shared_ptr<PlayableCharacter> p;
    bool saveState;

    public: 
        // Constructor(s)
        Dungeon(string fileName, shared_ptr<PlayableCharacter> p, bool save = false);
        Dungeon(shared_ptr<PlayableCharacter> p, int numFloors = 5);

        // Getters
        int get_curFloor();
        int get_numFloors(); 

        // Setters
        void set_curFloor(int curF); 
        void set_numFloors(int newF);

        // Misc
        void playerMove(Direction d);
        void playerAttack(Direction d);
        void playerUsePotion(Direction d);
};

#endif
