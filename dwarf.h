#ifndef DWARF_H
#define DWARF_H

#include "playablecharacter.h"

class Dwarf : public PlayableCharacter {
  public:
    Dwarf();
    std::string getRace() const override;
    int getAttack() const override;
    ~Dwarf();
};

#endif