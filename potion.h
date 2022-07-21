#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"

struct Potion : public Item {
    enum Type {RH, BA, BD, PH, WA, WD};
    virtual Type getType();
    virtual ~Potion() = 0;
};

#endif
