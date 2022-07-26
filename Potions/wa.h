#ifndef WA_H
#define WA_H

#include "potion.h"
#include "../TempEffects/tempeffect.h"

class PlayableCharacter;

class WA : public Potion {
    static bool visible;

  public:
  	WA() : Potion() {}
    Type getType() const override;
    
  private:
    bool isVisible()  const override;
    std::string getPotOutput() const override;
    void applyEffect(PlayableCharacter *pc) const override;
};

#endif
