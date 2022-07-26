#ifndef PH_H
#define PH_H

#include "potion.h"

class PlayableCharacter;

class PH : public Potion {
    static bool visible;

  public:
  	PH() : Potion() {}
    Type getType() const override;
    void setVisible();
  private:
    bool isVisible()  const  override;
    std::string getPotOutput() const override;
    void applyEffect(PlayableCharacter *pc) const override;
};

#endif
