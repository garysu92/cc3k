#ifndef BA_H
#define BA_H

#include "potion.h"

class BA : public Potion {
    static bool visible;
  public:
  	BA(): Potion() {}
    Type getType() const override ;
    void setVisible();
};

#endif
