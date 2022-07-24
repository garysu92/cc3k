#ifndef DRAGON_H
#define DRAGON_H

#include "../Entities/enemy.h"
#include "../posn.h"

class Dragon : public Enemy {
    Posn protectLocation;
  public:
    Dragon(int x, int y);
    bool isHostile();
    Posn getProtect() override;
};

#endif
