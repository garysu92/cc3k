#ifndef WD_H
#define WD_H

#include "potion.h"
#include "../TempEffects/tempeffect.h"

class PlayableCharacter;

class WD : public Potion {
    static bool visible;

  public:
  	WD() : Potion() {}
    std::string getPotType() const override;
    Type getType() const override;
    bool isVisible() override;
  private:
    void applyEffect(PlayableCharacter *pc) const override;
};


#endif
