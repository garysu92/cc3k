#ifndef CELL_H
#define CELL_H

#include <memory>
// Note all of the header below can likely be replaced with a forward declaration of the classes
#include "playablecharacter.h"
#include "enemy.h"
#include "item.h"

class Cell {
    int x, y; 
    PlayableCharacter *pc; // Not unique pointers as these objects can all move, and thus exist outside of the context of the Cell
    Enemy *enemy;
    unique_ptr<Item> item;
    char symbolRep;
    bool iseffWall; // Dictates whether or not the Cell effectively behaves as a wall, meaning the PC/Enemy cannot move through it.
    bool isStair = false; // Does this need be defined here?

    public:
        // Constructor
        Cell(int x, int y, char sym, bool iseffWall, bool isStair);

        // Destructor (Pure Virtual???)
        // Virtual ~Cell() = 0;

        // Getters
        int getX();
        int getY();
        PlayableCharacter *getPC();
        Enemy *getEnemy();
        // Item * getItem(); 
        char getsymbolRep();
        bool getiseffWall(); // function name weird???

        // Setters
        void setX(int x);
        void setY(int y);
        void setPC(PlayableCharacter *pc);
        void setEnemy(Enemy *enemy);
        void setItem(unique_ptr<Item> &item); // Unique ptr??
        void setsymbolRep(char sym);
        void setiseffWall(bool iseffWall);
        void setStair(); 
        
        // Checkers check what's atop of the Cell
        // bool hasEnemy();
        // bool hasPC();
        // bool hasItem();
};

#endif
