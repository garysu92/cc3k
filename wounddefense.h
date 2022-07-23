#ifndef WOUNDDEFENSE_H
#define WOUNDDEFENSE_H

#include <memory>
#include "tempeffect.h"

class PlayableCharacter;

class WoundDefense : public TempEffect {
  public:
    WoundDefense(std::shared_ptr<PlayableCharacter> pc);
    int getAttack() const override;
    int getDefense() const override;
    int getHP() const override;
    void setHP(int hp) override;
    //~WoundDefense();
};

#endif
