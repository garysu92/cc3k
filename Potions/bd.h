#ifndef BD_H
#define BD_H

#include "potion.h"

class BD : public Potion {
    static bool visible;
  public:
  	BD(): Potion() {}
    Type getType() override {
        return Potion::BD;
    }
    void setVisible() {
      visible = true;
    }
};

bool BD::visible = false;

#endif
