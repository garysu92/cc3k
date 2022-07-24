#include "tempeffect.h"
#include <memory>
#include <iostream> 
using namespace std;

class PlayableCharacter;

TempEffect::TempEffect(int atkEffect, int defEffect): atkEffect{atkEffect}, defEffect{defEffect} {}

int TempEffect::getAttackEffect() const {
    return atkEffect;
}

int TempEffect::getDefenseEffect() const {
    return defEffect;
}

TempEffect::~TempEffect(){}
