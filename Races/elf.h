#ifndef ELF_H
#define ELF_H

#include "../Entities/playablecharacter.h"

class Elf : public PlayableCharacter {
  public:
    Elf();
    std::string getRace() const override;
    ~Elf();
};

#endif
