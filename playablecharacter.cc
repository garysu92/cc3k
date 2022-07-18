#include <cmath>
#include <memory>
#include <string>
#include "playablecharacter.h"
#include "enemy.h"
#include <iostream>

using namespace std;

PlayableCharacter::PlayableCharacter(int atk, int def, int hp): attack{atk}, defense{def}, hp{hp}, maxHP{hp}, currGold{0} {}

string PlayableCharacter::getRace() const { return ""; }

void PlayableCharacter::takeDmg(Enemy *enemy) {
    cout << "playerchar has " << this->getHP() << " hp. ";
    int dmg = ceil((100.0 / (100.0 + defense)) * enemy->getAttack());
    setHP(max(0, this->getHP() - dmg));
    cout << "playerchar took " << dmg << " damage. now, he has " << this->getHP() << " hp" << endl;
}

void PlayableCharacter::dealDmg(unique_ptr<Enemy> enemy) {
    enemy->takeDmg(this);
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

void PlayableCharacter::setHP(int k) {
    if (k > maxHP || k < 0) return;
    hp = k;
}

void PlayableCharacter::giveCompass() {
    compass = true;
}

PlayableCharacter::~PlayableCharacter() {}