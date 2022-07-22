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
    // Constructor and Destructor
    Enemy(int atk, int def, int hp, int n);
    virtual ~Enemy() = 0;

    // Getters
    int getAttack() const;
    int getDefense() const;
    int getHP() const;
    int getMaxHP() const;

    // Checkers
    bool hasCompass();
    void giveCompass();
    void dropCompass();

    // Misc
    virtual bool isHostile() = 0;
    int goldDropped();
    void takeDmg(PlayableCharacter *pc);
    void dealDmg(std::unique_ptr<PlayableCharacter> &pc);
};

#endif
