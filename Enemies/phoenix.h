#ifndef PHOENIX_H
#define PHOENIX_H

#include <string>
#include "../Entities/enemy.h"
#include "../posn.h"
class Phoenix : public Enemy {
  public:
    Phoenix();
    std::string getType() const;
    bool isHostile();
    Posn getProtect() {
        return Posn{-1, -1};
    }
};

#endif
