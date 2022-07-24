#ifndef PH_H
#define PH_H

#include "potion.h"

class PH : public Potion {
    static bool visible;
  public:
  	PH(): Potion() {}
    Type getType() const override;
    void setVisible();
};

bool PH::visible = false;

#endif
