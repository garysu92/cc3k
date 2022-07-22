#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../Entities/enemy.h"

class Vampire : public Enemy {
  public:
    Vampire();
    bool isHostile();
};

#endif
