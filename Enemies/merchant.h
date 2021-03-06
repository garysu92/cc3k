#ifndef MERCHANT_H
#define MERCHANT_H

#include <string>
#include "../Entities/enemy.h"
#include "../posn.h"

class Merchant: public Enemy {
    static bool hostile;
  public:
    Merchant();
    bool isHostile();
    std::string getType() const;
  private:
    void takeDmg(PlayableCharacter *pc) override;
};

#endif
