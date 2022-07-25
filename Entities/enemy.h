#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include <string>

class PlayableCharacter;
class Cell;
class Posn;

class Enemy {
    const int goldDrop;
    int hp;
    int attack;
    int defense;
    bool hasCompass;
    char symbol;
    bool drag;
    bool hasDroppedGold;
  public:
    // Constructor and Destructor
    Enemy(int atk, int def, int hp, int n, char symbol, bool isDragon = false);
    virtual ~Enemy() = 0;

    // Getters
    int getAttack() const;
    int getDefense() const;
    int getHP() const;
    int getMaxHP() const;
    char getSymbol() const;
    bool isDragon();
    virtual std::string getType() const;

    // Checkers
    bool checkCompass();
    void giveCompass();
    void dropCompass();

    // Misc
    virtual bool isHostile() = 0;
    virtual Posn getProtect() = 0;

    // Non -virtual interface
    bool isDead() const;
    void attackPlayer(PlayableCharacter *pc);
    void getAttackedByPlayer(PlayableCharacter *pc);
    int goldDropped() const;
  
  protected:
    virtual void enemyAttack(PlayableCharacter *pc);
    virtual void deathProcedure();
    //void dropGold(PlayableCharacter *pc);
    //virtual void dealDmg(PlayableCharacter *pc);
    virtual void takeDmg(PlayableCharacter *pc);
};

#endif
