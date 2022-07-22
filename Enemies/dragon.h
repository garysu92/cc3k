#ifndef DRAGON_H
#define DRAGON_H

#include "../Entities/enemy.h"

class Dragon : public Enemy {
  public:
    Dragon();
    bool isHostile();
};

#endif
