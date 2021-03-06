#ifndef PHOENIX_H
#define PHOENIX_H

#include <string>
#include "../Entities/enemy.h"
#include "../posn.h"

class Phoenix : public Enemy {
  public:
    Phoenix();
    std::string getType() const override;
    bool isHostile();
};

#endif
