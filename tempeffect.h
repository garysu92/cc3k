#ifndef TEMPEFFECT_H
#define TEMPEFFECT_H

#include <memory>
#include "Entities/playablecharacter.h"

class TempEffect : public PlayableCharacter {
    std::unique_ptr<PlayableCharacter> p;
  public:
    TempEffect(std::unique_ptr<PlayableCharacter> pc, int atkEffect, int defEffect);
    virtual int getAttack() const override;
    virtual int getDefense() const override;
    virtual int getHP() const override;
    virtual void setHP(int k) override;
};

#endif