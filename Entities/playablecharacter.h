#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include <memory>
#include <string>
#include "../Cells/cell.h"

class Enemy;

class PlayableCharacter {
  protected:
    float curGold;
    const int maxHP;
    int hp;
    int attack;
    int defense;
    bool hasCompass;
    bool hasBarrierSuit;
    Cell * cellConnection;
    bool isDead;

  protected:
    // Setters
    virtual void setHP(int k);

  public:
    // Constructor and Destructor
    PlayableCharacter(int attack, int defense, int hp);
    virtual ~PlayableCharacter() = 0;

    // Getters
    virtual int getAttack() const;
    virtual int getDefense() const;
    virtual int getHP() const;
    int getMaxHP() const;
    Cell * getCell() const;
    bool getState() const;

    // Setters
    void setCell(Cell * newCell);
    void setState(bool alive);

    // Checkers
    bool checkCompass();
    bool checkBarrierSuit();

    // Misc
    virtual std::string getRace() const; // Maybe pure virtual??? Check implementation
    void takeDmg(Enemy *e);
    void dealDmg(Enemy *e);
    void giveCompass();
    void giveBarrierSuit();
};

#endif
