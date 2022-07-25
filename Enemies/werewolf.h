#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "../Entities/enemy.h"
#include "../posn.h"
class Werewolf : public Enemy {
  public:
    Werewolf();
    std::string getType() const;
    bool isHostile();
    Posn getProtect() {
        return Posn{-1, -1};
    }
};

#endif
