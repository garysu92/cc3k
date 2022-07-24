#ifndef BD_H
#define BD_H

#include "potion.h"

class BD : public Potion {
    static bool visible;
  public:
  	BD(): Potion() {}
    Type getType() const override ;
    void setVisible();
};

#endif
