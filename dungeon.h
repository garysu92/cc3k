#ifndef DUNGEON_H
#define DUNGEON_H

#include <memory>
#include <vector>
#include <string>
#include "floor.h"

class Dungeon {
    string fileName;
    std::vector<Floor> floors; 
    int curFloor;
    int numFloors; 

    public: 
        // Constructor
        Dungeon(string fileName, int curFloor=1, int numFloors=5)

        // Getters
        int get_curFloor();
        int get_numFloors(); 

        // Setters
        void set_curFloor(int curF); 
        void set_numFloors(int newF);
};

#endif
