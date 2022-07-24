#ifndef BOOSTATTACK_H
#define BOOSTATTACK_H

#include <memory>
#include "tempeffect.h"
class PlayableCharacter;

class BoostAttack : public TempEffect {
  public:
    BoostAttack();
    ~BoostAttack();
};

#endif
