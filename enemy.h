#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class PlayableCharacter;

class Enemy : public Entity {
    int goldDrop;
    int hp;
    int attack;
    int defense;
  public:
    Enemy(int atk, int def, int hp, int n);
    virtual bool isHostile() = 0;
    int goldDropped();
    virtual ~Enemy() = 0;
};

#endif