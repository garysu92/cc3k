#ifndef TROLL_H
#define TROLL_H

#include <string>
#include "../Entities/enemy.h"
#include "../posn.h"

class Troll : public Enemy {
  public:
    Troll();
    std::string getType() const override;
    bool isHostile();
};

#endif
