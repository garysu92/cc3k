#ifndef ENEMY_H
#define ENEMY_H

class PlayableCharacter;

class Enemy {
    const int goldDrop;
    int hp;
    int attack;
    int defense;
    bool compass = false;
  public:
    Enemy(int atk, int def, int hp, int n);
    virtual bool isHostile() = 0;
    int goldDropped();
    void takeDmg(PlayableCharacter *entity);
    void dealDmg(PlayableCharacter *entity);
    int getAttack() const;
    int getDefense() const;
    int getHP() const;
    int getMaxHP() const;
    void giveCompass();
    virtual ~Enemy() = 0;
};

#endif