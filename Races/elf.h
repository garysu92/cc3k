#ifndef ELF_H
#define ELF_H

#include "../Entities/playablecharacter.h"
#include <string>

class Elf : public PlayableCharacter {
  public:
    Elf();
    std::string getRace() const override;
    int getDefense() const override;
    int getAttack() const override;
    void addPermanentEffects(int hp, int atk, int def) override;
    ~Elf();
};

#endif
