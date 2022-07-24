#ifndef TROLL_H
#define TROLL_H

#include "../Entities/enemy.h"
#include "../posn.h"
class Troll : public Enemy {
  public:
    Troll();
    bool isHostile();
    Posn getProtect() {
        return Posn{-1, -1};
    }
};

#endif
