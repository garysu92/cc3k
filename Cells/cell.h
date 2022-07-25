#ifndef CELL_H
#define CELL_H


#include <memory> 

#include "../Entities/enemy.h"
#include "../Potions/potion.h"
#include "../Treasure/treasure.h"

class PlayableCharacter;

class Cell {
    int x, y; 
    PlayableCharacter *pc; // Not unique ptr as PC and enemy can move off of the Cell
    Enemy *enemy;
    std::unique_ptr<Potion> potion;
    std::unique_ptr<Treasure> treasure;
    bool bs;
    char symbolRep;
    bool isEffWall; // Dictates whether or not the Cell effectively behaves as a wall, meaning the PC/Enemy cannot move through it.
    bool isStair; // Does this need be defined here?
    bool comp;
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
        std::unique_ptr<Potion> &getPotion();
        std::unique_ptr<Treasure> &getTreasure();
        char getsymbolRep();
        bool getisEffWall();
        bool hasCompass();

        // Setters
        void setX(int x);
        void setY(int y);
        void setPC(PlayableCharacter *pc);
        void setEnemy(Enemy *enemy);
        void setPotion(std::unique_ptr<Potion> &potion);
        void setTreasure(std::unique_ptr<Treasure> &treasure);
        void setsymbolRep(char sym);
        void setisEffWall(bool isEffWall);
        void setStair(); 
        void setBarrierSuit(bool has);
        void setCompass(bool b);
        virtual void setVisibility() = 0;
        
        // Checkers check what's atop of the Cell
        bool hasEnemy();
        bool hasPC();
        bool hasPotion();
        bool hasTreasure();
        bool hasBarrierSuit();

        // Removing
        void clear();
};

#endif
