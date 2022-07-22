#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"

struct Potion : public Item {
  public:
    enum Type {RH, BA, BD, PH, WA, WD};
    virtual Type getType() = 0;
    virtual ~Potion() = 0;
};

#endif
