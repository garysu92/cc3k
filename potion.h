#ifndef POTION_H
#define POTION_H

#include <string>

struct Potion {
    char sym;
  public:
    Potion();
    enum Type {RH, BA, BD, PH, WA, WD};
    virtual Type getType() = 0;
    char getSymbol();
    virtual void setVisible() = 0;
    virtual ~Potion() = 0;
};

#endif
