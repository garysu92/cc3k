#ifndef PH_H
#define PH_H

#include "potion.h"

class PlayableCharacter;

class PH : public Potion {
    static bool visible;

  public:
  	PH() : Potion() {}
    std::string getPotType() const override;
    Type getType() const override;
    void setVisible();

  private:
    void applyEffect(PlayableCharacter *pc) const override;
};

#endif
