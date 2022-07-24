#ifndef TEMPEFFECT_H
#define TEMPEFFECT_H

#include <memory>
#include "Entities/playablecharacter.h"

class TempEffect {
  int atkEffect, defEffect;
  public:
    TempEffect( int atkEffect, int defEffect);
    int getAttackEffect() const;
    int getDefenseEffect() const;
    virtual ~TempEffect() = 0;
};

#endif
