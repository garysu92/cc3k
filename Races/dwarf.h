#ifndef DWARF_H
#define DWARF_H

#include "../Entities/playablecharacter.h"

#include <string>
class Dwarf : public PlayableCharacter {
  public:
    Dwarf();
    std::string getRace() const override;
    ~Dwarf();
    
  private:
    void addGold(int gold) override;
};

#endif
