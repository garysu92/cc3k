#ifndef WOUNDDEFENSE_H
#define WOUNDDEFENSE_H

#include "tempeffect.h"
class PlayableCharacter;

class WoundDefense : public TempEffect {
  public:
    WoundDefense(PlayableCharacter *pc);
    int getAttack() const override;
    int getDefense() const override;
};

#endif