#ifndef GOBLIN_H
#define GOBLIN_H

#include "../Entities/enemy.h"
#include "../posn.h"
class Goblin : public Enemy {
  public:
    Goblin();
    bool isHostile();
    Posn getProtect() {
        return Posn{-1, -1};
    }
};

#endif
