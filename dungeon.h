#ifndef DUNGEON_H
#define DUNGEON_H

#include <memory>
#include <vector>
#include <string>

#include "direction.h"
#include "Display/mapDisplay.h"

class Cell;
class PlayableCharacter;
class Floor;

const std::string floorLayout = "cc3kfloor.txt";

class Dungeon {
    std::string fileName;
    std::vector<Floor> floors;
    int curFloor;
    int numFloors;
    int floorWithBarrierSuit;
    PlayableCharacter *p;
    bool saveState;
    std::unique_ptr<Mapdisplay> curMap;

    public: 
        // Constructor(s)
        Dungeon(std::string fileName, PlayableCharacter *p, bool save = false);
        Dungeon(PlayableCharacter *p, int numFloors = 5);

        // Getters
        std::vector<std::vector<std::unique_ptr<Cell>>> & get_floorContents();
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
