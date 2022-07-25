#ifndef MERCHANT_H
#define MERCHANT_H

#include "../Entities/enemy.h"
#include "../posn.h"
class Merchant: public Enemy {
    static bool hostile;
  public:
    Merchant();
    bool isHostile();
    std::string getType() const;
    Posn getProtect() {
        return Posn{-1, -1};
    }
};

#endif
