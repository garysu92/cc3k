#ifndef POTION_H
#define POTION_H

#include <string>
class PlayableCharacter;

struct Potion {
    char sym;
  public:
    Potion();
    enum Type {RH, BA, BD, PH, WA, WD};
    virtual Type getType() const = 0;
    char getSymbol();
    virtual void setVisible() = 0;
    virtual ~Potion() = 0;
    virtual void applyEffect(PlayableCharacter *pc) const = 0;
};

#endif
