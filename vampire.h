#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "enemy.h"

class Vampire : public Enemy {
  public:
    Vampire();
    bool isHostile();
};

#endif