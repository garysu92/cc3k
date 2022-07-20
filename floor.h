#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "cell.h"
#include "playablecharacter.h"
#include "enemy.h"

class Posn;

class Floor {
    PlayableCharacter *p;
<<<<<<< HEAD
    std::vector<std::vector<Cell>> content;
    std::vector<std::vector<Posn>> chambers;
    std::vector<Enemy> enemies;
=======
    std::vector<std::vector<Cell>> content; // 2d array of the entire floor and the type of each cell (wall, tile, etc.)
    std::vector<std::vector<Posn>> chambers; // array of array of coordinates of every tile in each chamber, 
    std::vector<std::vector<int>> chamberMap; // 2d array containing the number(index) of the chamber that cells at that coordinate is located in
>>>>>>> 5f2ba6c643b05797cc4b95a4c0a980c104bd6090
  public:
    Floor(std::vector<std::vector<char>> v, PlayableCharacter *p);
    // generates based on PC, stairway, potions, gold, enemy
    void generate();
    void movePC();
    void moveEnemies();
};

#endif
