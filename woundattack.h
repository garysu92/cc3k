#ifndef WOUNDATTACK_H
#define WOUNDATTACK_H

#include "tempeffect.h"
class PlayableCharacter;

class WoundAttack : public TempEffect {
  public:
    WoundAttack(PlayableCharacter *pc);
    int getAttack() const override;
    int getDefense() const override;
    int getHP() const override;
    void setHP(int hp) override;
};

#endif