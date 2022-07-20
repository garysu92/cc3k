#ifndef BA_H
#define BA_H

#include "potion.h"

class BA : public Potion {
    static bool visible;
  public:
    Type getType() override {
        return Potion::BA;
    }
    void setVisible() {
      visible = true;
    }
};

bool BA::visible = false;

#endif