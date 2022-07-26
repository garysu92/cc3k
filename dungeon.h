#ifndef DUNGEON_H
#define DUNGEON_H

#include <memory>
#include <vector>
#include <string>

#include "direction.h"
#include "Display/mapDisplay.h"
#include "Display/actionDisplay.h"
#include "floor.h"

class Cell;
class PlayableCharacter;

const std::string floorLayout = "cc3kfloor.txt";

class Dungeon {
    std::string fileName;
    bool dev;
    std::vector<Floor> floors;
    int curFloor;
    int numFloors;
    int floorWithBarrierSuit;
    PlayableCharacter *p;
    bool saveState;
    std::unique_ptr<Mapdisplay> curMap;
    std::unique_ptr<Actiondisplay> curActionBar;

    public: 
        // Constructor(s)
        Dungeon(std::string fileName, PlayableCharacter *p, bool dev, bool save = false);
        Dungeon(PlayableCharacter *p, bool dev, int numFloors = 5);

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
        void printGame();
        bool end() const;

    private:
        void nextFloor();
        void postMoveCheck();
};

#endif
