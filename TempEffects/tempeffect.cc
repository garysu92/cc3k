#include <memory>
#include <iostream> 
#include "tempeffect.h"

using namespace std;

TempEffect::TempEffect(int atkEffect, int defEffect): atkEffect{atkEffect}, defEffect{defEffect} {}

int TempEffect::getAttackEffect() const {
    return atkEffect;
}

int TempEffect::getDefenseEffect() const {
    return defEffect;
}

TempEffect::~TempEffect(){}
