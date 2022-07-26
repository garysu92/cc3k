#ifndef RH_H
#define RH_H

#include "potion.h"

class PlayableCharacter;

class RH : public Potion {
    static bool visible;

  public:
  	RH() : Potion() {}
    Type getType() const override;
    
  private:
    bool isVisible() const  override;
    std::string getPotOutput() const override;
    void applyEffect(PlayableCharacter *pc) const override;
};


#endif
