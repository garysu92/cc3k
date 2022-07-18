#include <cmath>
#include <string>
#include "playablecharacter.h"
#include "enemy.h"
#include <iostream>

using namespace std;

PlayableCharacter::PlayableCharacter(int atk, int def, int hp): attack{atk}, defense{def}, hp{hp}, maxHP{hp}, currGold{0} {}

string PlayableCharacter::getRace() const { return ""; }

void PlayableCharacter::takeDmg(Enemy *pc) {
    cout << "playerchar has " << hp << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * pc->getAttack());
    hp = max(0, hp - dmg);
    cout << "playerchar took " << dmg << " damage. now, he has " << hp << " hp" << endl;
}

void PlayableCharacter::dealDmg(Enemy *pc) {
    pc->takeDmg(this);
}

int PlayableCharacter::getAttack() const {
    return attack;
}

int PlayableCharacter::getDefense() const {
    return defense;
}

int PlayableCharacter::getHP() const {
    return hp;
}

void PlayableCharacter::giveCompass() {
    compass = true;
}

PlayableCharacter::~PlayableCharacter() {}