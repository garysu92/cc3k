#ifndef TROLL_H
#define TROLL_H

<<<<<<< HEAD
#include <string.h>
=======
#include <string>
>>>>>>> d670a007c2f947c7fcc7b76b33f6860fd501b710
#include "../Entities/enemy.h"
#include "../posn.h"

class Troll : public Enemy {
  public:
    Troll();
    std::string getType() const override;
    bool isHostile();
    Posn getProtect() {
        return Posn{-1, -1};
    }
};

#endif
