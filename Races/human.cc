#include <string>
#include "../Entities/playablecharacter.h"
#include "human.h"

using namespace std;

Human::Human(): PlayableCharacter{20, 20, 140} {}

string Human::getRace() const {
    return "Human";
}

double Human::playerGetScore() const {
    return 1.5 * getcurGold();
}

Human::~Human() {}
