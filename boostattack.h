#ifndef BOOSTATTACK_H
#define BOOSTATTACK_H

#include "tempeffect.h"
class PlayableCharacter;

class BoostAttack : public TempEffect {
  public:
    BoostAttack(PlayableCharacter *pc);
    int getAttack() const override;
    int getDefense() const override;
    int getHP() const override;
    void setHP(int hp) override;
};

#endif