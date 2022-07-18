#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include <string>

class Enemy;

class PlayableCharacter {
  protected:
    float currGold = 0;
    const int maxHP;
    int hp;
    int attack;
    int defense;
    bool compass = false;
  public:
    PlayableCharacter(int attack, int defense, int hp);
    virtual std::string getRace() const;
    void takeDmg(Enemy *entity);
    void dealDmg(Enemy *entity);
    virtual int getAttack() const;
    virtual int getDefense() const;
    virtual int getHP() const;
    virtual void setHP(int k);
    int getMaxHP() const;
    void giveCompass();
    virtual ~PlayableCharacter() = 0;
};

#endif