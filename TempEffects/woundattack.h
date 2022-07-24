#ifndef WOUNDATTACK_H
#define WOUNDATTACK_H

#include <memory>
#include "tempeffect.h"
class PlayableCharacter;

class WoundAttack : public TempEffect {
  public:
    WoundAttack();
    ~WoundAttack();
};

#endif
