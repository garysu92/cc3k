#ifndef RH_H
#define RH_H

#include "potion.h"

class RH : public Potion {
    static bool visible;
  public:
  	RH(): Potion() {}
    Type getType() override {
        return Potion::RH;
    }
    void setVisible() {
      visible = true;
    }
};

bool RH::visible = false;

#endif
