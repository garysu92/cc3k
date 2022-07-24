#ifndef WD_H
#define WD_H

#include "potion.h"

class WD : public Potion {
    static bool visible;
  public:
  	WD(): Potion() {}
    Type getType() const override;
    void setVisible();
    void applyEffect(PlayableCharacter *pc) const override;
};


#endif
