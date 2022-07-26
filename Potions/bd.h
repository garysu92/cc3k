#ifndef BD_H
#define BD_H

#include "potion.h"

class PlayableCharacter;

class BD : public Potion {
    static bool visible;

  public:
  	BD() : Potion() {}
    std::string getPotType() const override;
    Type getType() const override;
    bool isVisible() override;
  private:
    void applyEffect(PlayableCharacter *pc) const override;
};

#endif
