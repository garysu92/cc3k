#ifndef BOOSTATTACK_H
#define BOOSTATTACK_H

#include <memory>
#include "tempeffect.h"
class PlayableCharacter;

class BoostAttack : public TempEffect {
  public:
    BoostAttack(std::shared_ptr<PlayableCharacter> pc);
    int getAttack() const override;
    int getDefense() const override;
    int getHP() const override;
    void setHP(int hp) override;
    //~BoostAttack();
};

#endif
