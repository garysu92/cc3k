#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <utility>
#include "Cells/cell.h"
#include "Entities/playablecharacter.h"
#include "Entities/enemy.h"
#include "posn.h"
#include "direction.h"

class Posn;

class Floor {
    PlayableCharacter *p;
    std::vector<std::vector<std::unique_ptr<Cell>>> content; // 2d array of the entire floor and the type of each cell (wall, tile, etc.)
    std::vector<std::vector<Posn>> chambers; // array of array of coordinates of every tile in each chamber, 
    std::vector<std::vector<int>> chamberMap; // 2d array containing the number(index) of the chamber that cells at that coordinate is located in
    std::vector<std::pair<std::unique_ptr<Enemy>, Posn>> enemies;
    Posn stairLocation;
    Posn pcLocation;
    Posn bsLocation;
    bool bs;
    bool isOnStair = false;;
    
  public:
    // Floor(const std::vector<std::vector<char>> &v, PlayableCharacter *p);
    Floor(const std::vector<std::vector<char>> &v, PlayableCharacter *p, bool barrierSuit = false, bool exactLayout = false, bool save = false);
    // generates based on PC, stairway, potions, gold, enemy
    void generate();
    void movePC();
    void updateEnemies();
    std::vector<Posn> neighbours(int x, int y, bool isGold, bool isPlayer);
    void print();
    void movePC(Direction d);
    std::vector<std::vector<std::unique_ptr<Cell>>> & getContents();
    Posn getCoords(Direction d);
    void usePotion(Direction d);
    void attack(Direction d);
    bool PConStair();
};

#endif
