#ifndef PH_H
#define PH_H

#include "potion.h"

class PlayableCharacter;

class PH : public Potion {
    static bool visible;
  public:
  	PH(): Potion() {}
    Type getType() const override;
    void setVisible();
  private:
    void applyEffect(PlayableCharacter *pc) const override;
};

bool PH::visible = false;

#endif
