#ifndef WD_H
#define WD_H

#include "potion.h"

class WD : public Potion {
    static bool visible;
  public:
    Type getType() override {
        return Potion::WD;
    }
    void setVisible() {
      visible = true;
    }
};

bool WD::visible = false;

#endif