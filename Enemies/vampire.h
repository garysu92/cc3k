#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "../Entities/enemy.h"
#include "../posn.h"

class Vampire : public Enemy {
  public:
    Vampire();
    std::string getType() const;
    bool isHostile();
    Posn getProtect() {
		return Posn{-1, -1};
    }
};

#endif
