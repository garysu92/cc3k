#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

class PlayableCharacter;
class Cell;

class Enemy {
    const int goldDrop;
    int hp;
    int attack;
    int defense;
    bool hasCompass;
    char symbol;
  public:
    // Constructor and Destructor
    Enemy(int atk, int def, int hp, int n, char symbol);
    virtual ~Enemy() = 0;

    // Getters
    int getAttack() const;
    int getDefense() const;
    int getHP() const;
    int getMaxHP() const;
    char getSymbol() const;

    // Checkers
    bool checkCompass();
    void giveCompass();
    void dropCompass();

    // Misc
    virtual bool isHostile() = 0;
    int goldDropped();
    void takeDmg(PlayableCharacter *pc);

    // Non -virtual interface
    // bool isDead();
    // void attackPlayer(PlayableCharacter *pc);
    // void getAttackedByPlayer(PlayableCharacter *pc);
    void dealDmg(PlayableCharacter *pc);
};

#endif
