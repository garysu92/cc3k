#ifndef CELL_H
#define CELL_H

#include "../item.h"
#include "../Entities/enemy.h"

class PlayableCharacter;

#include <memory> 

class Cell {
    int x, y; 
    PlayableCharacter *pc; // Not unique ptr as PC and enemy can move off of the Cell
    Enemy *enemy;
    std::unique_ptr<Item> item;
    char symbolRep;
    bool isEffWall; // Dictates whether or not the Cell effectively behaves as a wall, meaning the PC/Enemy cannot move through it.
    bool isStair; // Does this need be defined here?

    public:
        // Constructor
        Cell(int x, int y, char sym, bool isEffWall, bool isStair);

        // Destructor (Pure Virtual???)
        // Virtual ~Cell() = 0;

        // Getters
        int getX();
        int getY();
        PlayableCharacter *getPC();
        Enemy *getEnemy();
        std::unique_ptr<Item> &getItem(); 
        char getsymbolRep();
        bool getisEffWall();

        // Setters
        void setX(int x);
        void setY(int y);
        void setPC(PlayableCharacter *pc);
        void setEnemy(Enemy *enemy);
        void setItem(std::unique_ptr<Item> &item);
        void setsymbolRep(char sym);
        void setisEffWall(bool isEffWall);
        void setStair(); 
        
        // Checkers check what's atop of the Cell
        bool hasEnemy();
        bool hasPC();
        bool hasItem();

        // Removing
        void clear();
};

#endif
