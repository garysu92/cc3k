#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include <string>
#include "entity.h"

class Enemy;

class PlayableCharacter : public Entity {
  protected:
    float currGold = 0;
  public:
    PlayableCharacter(int attack, int defense, int hp);
    virtual std::string getRace() const;
    virtual ~PlayableCharacter() = 0;
};

#endif