#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"

class Merchant: public Enemy {
    static bool hostile;
  public:
    Merchant();
    bool isHostile();
};

#endif