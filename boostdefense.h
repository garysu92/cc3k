#ifndef BOOSTDEFENSE_H
#define BOOSTDEFENSE_H

#include <memory>
#include "tempeffect.h"
class PlayableCharacter;

class BoostDefense : public TempEffect {
  public:
    BoostDefense(std::shared_ptr<PlayableCharacter> pc);
    int getAttack() const override;
    int getDefense() const override;
    int getHP() const override;
    void setHP(int hp) override;
    //~BoostDefense();
};

#endif
