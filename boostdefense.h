#ifndef BOOSTDEFENSE_H
#define BOOSTDEFENSE_H

#include "tempeffect.h"
class PlayableCharacter;

class BoostDefense : public TempEffect {
  public:
    BoostDefense(PlayableCharacter *pc);
    int getAttack() const override;
    int getDefense() const override;
    int getHP() const override;
    void setHP(int hp) override;
};

#endif