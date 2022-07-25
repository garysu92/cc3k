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
    float curGold;
    const int maxHP;
    int hp;
    int attack;
    int defense;
    bool hasCompass;
    bool hasBarrierSuit;
    Cell * cellConnection;
    bool isDead;
    std::vector<std::unique_ptr<TempEffect>> tempEffects;

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
    bool getState() const;

    // Setters
    void setCell(Cell * newCell);
    void setState(bool alive);
    virtual void setHP(int k);

    // Checkers
    bool checkCompass();
    bool checkBarrierSuit();

    // Misc
    virtual std::string getRace() const; // Maybe pure virtual??? Check implementation
    
    //void dealDmg(Enemy *e);
    void giveCompass();
    void giveBarrierSuit();
    void usePotion(Potion *p);
    void removeTempEffects();
    void addTempEffect(std::unique_ptr<TempEffect>);
    virtual void addPermanentEffects(int hp, int atk, int def);

    void attackEnemy(Enemy *em);
    void getAttackedByEnemy(Enemy *em);
    void getDroppedGold(Enemy *em);
    void pickupTreasure(Treasure *t);

  private:
    virtual void addGold(int gold);
    void takeDmg(Enemy *e);
};

#endif
