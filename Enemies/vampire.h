#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <string>
#include "../Entities/enemy.h"
#include "../posn.h"

class Vampire : public Enemy {
  public:
    Vampire();
    std::string getType() const override;
    bool isHostile();
};

#endif
