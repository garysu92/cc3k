#ifndef PH_H
#define PH_H

#include "potion.h"

class PH : public Potion {
    static bool visible;
  public:
    Type getType() override {
        return Potion::PH;
    }
    void setVisible() {
      visible = true;
    }
};

bool PH::visible = false;

#endif
