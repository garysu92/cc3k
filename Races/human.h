#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "../Entities/playablecharacter.h"

class Human: public PlayableCharacter {
  public:
    Human();
    std::string getRace() const override;
    ~Human();
    
  private:
    double playerGetScore() override;
};

#endif
