#ifndef PHOENIX_H
#define PHOENIX_H

#include "../Entities/enemy.h"

class Phoenix : public Enemy {
  public:
    Phoenix();
    bool isHostile();
};

#endif
