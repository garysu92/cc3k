#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "cell.h"
#include "playablecharacter.h"
#include "enemy.h"

class Posn;

class Floor {
    PlayableCharacter *p;
    std::vector<std::vector<Cell>> content;
    std::vector<std::vector<Posn>> chambers;
    std::vector<Enemy> enemies;
  public:
    Floor(std::vector<std::vector<char>> v, PlayableCharacter *p);
    // generates based on PC, stairway, potions, gold, enemy
    void generate();
    void movePC();
    void moveEnemies();
};

#endif