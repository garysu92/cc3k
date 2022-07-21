#ifndef BD_H
#define BD_H

#include "potion.h"

class BD : public Potion {
    static bool visible;
  public:
    Type getType() override {
        return Potion::BD;
    }
    void setVisible() {
      visible = true;
    }
};

bool BD::visible = false;

#endif
