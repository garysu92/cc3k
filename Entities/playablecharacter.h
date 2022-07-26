#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include <memory>
#include <vector>
#include <string>
#include "../Cells/cell.h"
#include "../TempEffects/tempeffect.h"

class Enemy;

class PlayableCharacter {
  protected:
    double curGold;
    const int maxHP;
    int hp;
    int attack;
    int defense;
    bool hasCompass;
    bool hasBarrierSuit;
    Cell * cellConnection;
    bool dead;
    std::vector<std::unique_ptr<TempEffect>> tempEffects;
    std::string curAction;

  public:
    // Constructor and Destructor
    PlayableCharacter(int attack, int defense, int hp);
    virtual ~PlayableCharacter() = 0;

    // Getters
    virtual int getAttack() const;
    virtual int getDefense() const;
    virtual int getHP() const;
    float getcurGold() const;
    int getMaxHP() const;
    Cell * getCell() const;
    bool getDead() const;
    std::string getcurAction() const;

    // Setters
    void setCell(Cell * newCell);
    virtual void setHP(int k);
    void setcurAction(std::string curAction);
    void setCompass(bool hasCompass);
    void setBarrierSuit(bool hasBarrierSuit);

    // Checkers
    bool checkCompass();
    bool checkBarrierSuit();

    // Misc
    virtual std::string getRace() const; // Maybe pure virtual??? Check implementation
    //void dealDmg(Enemy *e);
    void usePotion(Potion *p);
    void removeTempEffects();
    void addTempEffect(std::unique_ptr<TempEffect>);
    virtual void addPermanentEffects(int hp, int atk, int def);
    void attackEnemy(Enemy *em);
    void getAttackedByEnemy(Enemy *em);
    void getDroppedGold(Enemy *em);
    void pickupTreasure(Treasure *t);
    double getScore(); 
    
  private:
    virtual void addGold(int gold);
    virtual double playerGetScore();
    void takeDmg(Enemy *e);
    void setDead(bool alive);
};

#endif
