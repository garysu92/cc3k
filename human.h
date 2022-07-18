#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "playablecharacter.h"

class Human: public PlayableCharacter {
  public:
    Human();
    std::string getRace() const override;
    int getAttack() const override;
    ~Human();
};

#endif