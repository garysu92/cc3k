#include "../Entities/playablecharacter.h"
#include "elf.h"

using namespace std;

Elf::Elf(): PlayableCharacter{30, 10, 140} {}

string Elf::getRace() const {
    return "Elf";
}

void Elf::addGold(int gold) {
    curGold += 2 * gold;
}

void Elf::addPermanentEffects(int hp, int atk, int def) {
    this->hp += abs(hp);
    this->attack += abs(atk);
    this->defense += abs(def);
    if (this->hp > maxHP) {
        this->hp = maxHP;
    } 
}

int Elf::getAttack() const {
    int atk = attack;
    for (int i = 0; i < tempEffects.size(); i++) {
        atk += abs(tempEffects.at(i)->getAttackEffect());
    }
    return atk;
}

int Elf::getDefense() const {
    int def = defense;
    for (int i = 0; i < tempEffects.size(); i++) {
        def += abs(tempEffects.at(i)->getDefenseEffect());
    }
    return def;
}

Elf::~Elf() {}
