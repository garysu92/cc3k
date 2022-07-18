#ifndef LOWERATTACK_H
#define LOWERATTACK_H

#include "tempeffect.h"
class PlayableCharacter;

class LowerAttack : public TempEffect {
  public:
    LowerAttack(PlayableCharacter *pc);
};

#endif