#ifndef GOBLIN_H
#define GOBLIN_H

#include "../Entities/enemy.h"

class Goblin : public Enemy {
  public:
    Goblin();
    bool isHostile();
};

#endif
