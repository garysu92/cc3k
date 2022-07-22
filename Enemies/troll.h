#ifndef TROLL_H
#define TROLL_H

#include "enemy.h"

class Troll : public Enemy {
  public:
    Troll();
    bool isHostile();
};

#endif
