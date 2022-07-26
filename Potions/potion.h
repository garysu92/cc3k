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
    std::string getPotType() const;
    virtual Type getType() const = 0;
    char getSymbol();
    virtual ~Potion() = 0;
    void potionGetUsed(PlayableCharacter *pc);

  private:
    virtual bool isVisible() const;
    virtual std::string getPotOutput() const;
    virtual void applyEffect(PlayableCharacter *pc) const = 0;
};

#endif
