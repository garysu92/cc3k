#ifndef BD_H
#define BD_H

#include "potion.h"

class PlayableCharacter;

class BD : public Potion {
    static bool visible;

  public:
  	BD() : Potion() {}
    Type getType() const override;
    
  private:
    bool isVisible() const override;
    std::string getPotOutput() const override;
    void applyEffect(PlayableCharacter *pc) const override;
};

#endif
