#ifndef TEMPEFFECT_H
#define TEMPEFFECT_H

#include "playablecharacter.h"

class TempEffect : public PlayableCharacter {
    PlayableCharacter *p;
  public:
    TempEffect(PlayableCharacter *pc, int atkEffect, int defEffect);
    virtual int getAttack() const override;
    virtual int getDefense() const override;
};

#endif