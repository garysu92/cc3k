#include "dwarf.h"

using namespace std;

Dwarf::Dwarf(): PlayableCharacter{20, 30, 100} {}

string Dwarf::getRace() const {
    return "Dwarf";
}

int Dwarf::getAttack() const {
    return PlayableCharacter::getAttack();
}

Dwarf::~Dwarf() {}