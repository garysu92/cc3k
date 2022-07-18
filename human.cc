#include "human.h"

using namespace std;

Human::Human(): PlayableCharacter{20, 20, 140} {}

string Human::getRace() const {
    return "Human";
}

int Human::getAttack() const {
    return PlayableCharacter::getAttack();
}

Human::~Human() {}