#ifndef CELL_H
#define CELL_H

#include "playablecharacter.h"
#include "enemy.h"
// #include "item.h"

class Cell {
    int x, y; 
    PlayableCharacter * PC; // Not unique pointers as these objects can all move, and thus exist outside of the context of the Cell
    Enemy * foe;
    // Item * onFloor;
    char symbolRep;

    public:
        Cell(int x, int y);

        // Getters
        int getX();
        int getY();
        PlayableCharacter * getPC();
        Enemy * getEnemy();
        // Item * getItem(); // Possibly a unique pointer???
        char getsymbolRep();

        // Setters
        void setX(int x);
        void setY(int y);
        void setPC(PlayableCharacter * PC);
        void setEnemy(Enemy * foe);
        // void setItem(Item * onFloor);
        void setsymbolRep(char sym);
};

#endif
