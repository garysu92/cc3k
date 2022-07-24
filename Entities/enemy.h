#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

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
  private:
    virtual void enemyAttack(PlayableCharacter *pc) = 0;
    //void dropGold(PlayableCharacter *pc);
    void dealDmg(PlayableCharacter *pc);
    void takeDmg(PlayableCharacter *pc);
};

#endif
