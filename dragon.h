#ifndef DRAGON_H
#define DRAGIN_H

#include "enemy.h"

class Dragon : public Enemy {
  public:
    Dragon();
    bool isHostile();
};

#endif