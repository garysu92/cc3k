#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "enemy.h"

class Werewolf : public Enemy {
  public:
    Werewolf();
    bool isHostile();
};

#endif
