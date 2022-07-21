#ifndef CELL_H
#define CELL_H

// All of these can likely be replaced with a forward declaration of the classes
#include "playablecharacter.h"
#include "enemy.h" 
// #include "item.h"

class Cell {
    int x, y; 
    PlayableCharacter * PC; // Not unique pointers as these objects can all move, and thus exist outside of the context of the Cell
    Enemy * foe;
    // Item * onFloor;
    char symbolRep;
    bool iseffWall; // Dictates whether or not the Cell effectively behaves as a wall, meaning the PC/Enemy cannot move through it.

    public:
        // Constructor
        Cell(int x, int y, char sym, bool iseffWall);

        // Destructor (Pure Virtual???)
        // Virtual ~Cell() = 0;

        // Getters
        int getX();
        int getY();
        PlayableCharacter * getPC();
        Enemy * getEnemy();
        // Item * getItem(); // Possibly a unique pointer???
        char getsymbolRep();
        bool getiseffWall(); // function name weird?

        // Setters
        void setX(int x);
        void setY(int y);
        void setPC(PlayableCharacter * PC);
        void setEnemy(Enemy * foe);
        // void setItem(Item * onFloor);
        void setsymbolRep(char sym);
        void setiseffWall(bool iseffWall);
};

#endif
