#ifndef TREASURE_H
#define TREASURE_H

#include "object.h"

class Treasure : public Object {
    int amount;
  public:
    Treasure(int amount);
    virtual ~Treasure() = 0;
    int getAmount();
};

#endif