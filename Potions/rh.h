#ifndef RH_H
#define RH_H

#include "potion.h"

class RH : public Potion {
    static bool visible;
  public:
  	RH(): Potion() {}
    Type getType() const override;
    void setVisible();
};

bool RH::visible = false;

#endif
