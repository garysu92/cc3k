#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

class PlayableCharacter;

class Enemy {
    const int goldDrop;
    int hp;
    int attack;
    int defense;
    bool compass = false;
  public:
    Enemy(int atk, int def, int hp, int n);
    virtual bool isHostile() = 0;
    int goldDropped();
    void takeDmg(PlayableCharacter *pc);
    void dealDmg(std::unique_ptr<PlayableCharacter> &pc);
    int getAttack() const;
    int getDefense() const;
    int getHP() const;
    int getMaxHP() const;
    bool hasCompass();
    void giveCompass();
    void dropCompass();
    virtual ~Enemy() = 0;
};

#endif