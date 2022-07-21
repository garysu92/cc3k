#ifndef CELL_H
#define CELL_H

#include <memory>
#include "playablecharacter.h"
#include "enemy.h"
#include "item.h"

class Cell {
    int x, y; 
    PlayableCharacter *pc; // Not unique pointers as these objects can all move, and thus exist outside of the context of the Cell
    Enemy *enemy;
    unique_ptr<Item> item;
    char symbolRep;
    bool isStair = false;

    public:
        Cell(int x, int y, char sym);

        // Getters
        int getX();
        int getY();
        PlayableCharacter *getPC();
        Enemy *getEnemy();
        // Item * getItem(); // Possibly a unique pointer???
        char getsymbolRep();

        // Setters
        void setX(int x);
        void setY(int y);
        void setPC(PlayableCharacter *pc);
        void setEnemy(Enemy *enemy);
        void setItem(unique_ptr<Item> &item);
        void setsymbolRep(char sym);
        void setStair();
        
        // check what's on this cell
        bool hasEnemy();
        bool hasPC();
        bool hasItem();
};

#endif
