#ifndef RH_H
#define RH_H

#include "potion.h"

class PlayableCharacter;

class RH : public Potion {
    static bool visible;

  public:
  	RH() : Potion() {}
    std::string getPotType() const override;
    Type getType() const override;
    bool isVisible() override;
  private:
    void applyEffect(PlayableCharacter *pc) const override;
};


#endif
