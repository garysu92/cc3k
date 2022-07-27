#ifndef DRAGON_H
#define DRAGON_H

#include <string>
#include "../Entities/enemy.h"
#include "../posn.h"

class Dragon : public Enemy {
    Posn protectLocation;
    bool hostile;

  public:
    std::string getType() const override;
    Dragon(int x, int y);
    bool isHostile();
    Posn getProtect() override;
    
};

#endif
