#ifndef WOUNDATTACK_H
#define WOUNDATTACK_H

#include <memory>
#include "tempeffect.h"
class PlayableCharacter;

class WoundAttack : public TempEffect {
  public:
    WoundAttack(std::unique_ptr<PlayableCharacter> pc);
    int getAttack() const override;
    int getDefense() const override;
    int getHP() const override;
    void setHP(int hp) override;
    //~WoundAttack();
};

#endif