#ifndef WA_H
#define WA_H

#include "potion.h"
#include "../TempEffects/tempeffect.h"

class PlayableCharacter;

class WA : public Potion {
    static bool visible;

  public:
  	WA() : Potion() {}
    std::string getPotType() const override;
    Type getType() const override;
    bool isVisible() override;
  private:
    void applyEffect(PlayableCharacter *pc) const override;
};

#endif
