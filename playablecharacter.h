#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include <memory>
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
    void takeDmg(Enemy *e);
    void dealDmg(std::unique_ptr<Enemy> e);
    virtual int getAttack() const;
    virtual int getDefense() const;
    virtual int getHP() const;
    virtual void setHP(int k);
    int getMaxHP() const;
    bool hasCompass();
    void giveCompass();
    virtual ~PlayableCharacter() = 0;
};

#endif