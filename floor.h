#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "cell.h"

class Posn;

class Floor {
    std::vector<std::vector<Cell>> content;
    std::vector<std::vector<Posn>> chambers;
  public:
    Floor(std::vector<std::vector<char>> v);
    // generates based on PC, stairway, potions, gold, enemy
    void generate();
};

#endif