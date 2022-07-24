#ifndef WA_H
#define WA_H

#include "potion.h"

class WA : public Potion {
    static bool visible;
  public:
  	WA(): Potion() {}
    Type getType() override {
        return Potion::WA;
    }
    void setVisible() {
      visible = true;
    }
};

bool WA::visible = false;

#endif
