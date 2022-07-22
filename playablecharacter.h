#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include <memory>
#include <string>

class Enemy;

class PlayableCharacter {
  protected:
    float curGold = 0;
    const int maxHP;
    int hp;
    int attack;
    int defense;
    bool compass = false;

  public:
    PlayableCharacter(int attack, int defense, int hp); // Constructor
    virtual ~PlayableCharacter() = 0;                   // Destructor

    virtual std::string getRace() const;
    void takeDmg(Enemy *e);
    void dealDmg(std::unique_ptr<Enemy> &e);
    void giveCompass();

    // Getters
    virtual int getAttack() const;
    virtual int getDefense() const;
    virtual int getHP() const;
    int getMaxHP() const;

    // Setters
    virtual void setHP(int k);

    // Checkers
    bool hasCompass();
};

#endif
