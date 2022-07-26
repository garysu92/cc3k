#ifndef ORC_H
#define ORC_H

#include <string>
#include "../Entities/playablecharacter.h"

class Orc : public PlayableCharacter {
  public:
    Orc();
    std::string getRace() const override;
    ~Orc();

  private:
    void addGold(int gold) override;
};

#endif
