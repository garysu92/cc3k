#ifndef BA_H
#define BA_H

#include "potion.h"

class PlayableCharacter;

class BA : public Potion {
    static bool visible;

  public:
  	BA() : Potion() {}
    std::string getPotType() const override;
    Type getType() const override;
    void setVisible();

  private:
    void applyEffect(PlayableCharacter *pc) const override;

};

#endif
