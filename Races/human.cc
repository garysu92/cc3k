#include "../Entities/playablecharacter.h"
#include "human.h"
#include <string>

using namespace std;

Human::Human(): PlayableCharacter{20, 20, 140} {}

string Human::getRace() const {
    return "Human";
}

Human::~Human() {}
