#ifndef POTION_H
#define POTION_H

#include <string>
#include <memory>

class PlayableCharacter;

class Potion {
    char sym;
    bool used;

  public:
    Potion();
    enum Type {RH, BA, BD, PH, WA, WD};
    virtual std::string getPotType() const = 0;
    virtual Type getType() const = 0;
    char getSymbol();
    virtual bool isVisible() = 0;
    virtual ~Potion() = 0;
    void potionGetUsed(PlayableCharacter *pc);

  private:
    virtual void applyEffect(PlayableCharacter *pc) const = 0;
};

#endif
