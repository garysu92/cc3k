#include "../Entities/playablecharacter.h"
#include "orc.h"

using namespace std;

Orc::Orc(): PlayableCharacter{30, 25, 180} {}

string Orc::getRace() const {
    return "Orc";
}

void Orc::addGold(int gold) {
    curGold += gold / 2.0;
}

Orc::~Orc() {}
