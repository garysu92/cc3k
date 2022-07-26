#ifndef BA_H
#define BA_H

#include "potion.h"

class PlayableCharacter;

class BA : public Potion {
    static bool visible;

  public:
  	BA() : Potion() {}
    Type getType() const override;
    
  private:
    bool isVisible() const override;
    std::string getPotOutput() const override;
    void applyEffect(PlayableCharacter *pc) const override;

};

#endif
