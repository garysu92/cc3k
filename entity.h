#ifndef ENTITY_H
#define ENTITY_H

class Entity {
  protected:
    const int maxHP;
    int hp;
    int attack;
    int defense;
    bool compass = false;
  public:
    Entity(int atk, int def, int hp);
    void takeDmg(Entity *entity);
    void dealDmg(Entity *entity);
    int getAttack() const;
    int getDefense() const;
    int getHP() const;
    int getMaxHP() const;
    void giveCompass();
    virtual ~Entity() = 0;
};

#endif