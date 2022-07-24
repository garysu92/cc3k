#ifndef WA_H
#define WA_H

#include "potion.h"

class WA : public Potion {
    static bool visible;
  public:
  	WA(): Potion() {}
    Type getType() const override;
    void setVisible();
    void applyEffect(PlayableCharacter *pc) const override;
};

bool WA::visible = false;

#endif