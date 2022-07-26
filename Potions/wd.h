#ifndef WD_H
#define WD_H

#include "potion.h"
#include "../TempEffects/tempeffect.h"

class PlayableCharacter;

class WD : public Potion {
    static bool visible;

  public:
  	WD() : Potion() {}
    Type getType() const override;
  private:
    bool isVisible()  const override;
    std::string getPotOutput() const override;
    void applyEffect(PlayableCharacter *pc) const override;
};

#endif
