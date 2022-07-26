#include <string>
#include "../Entities/playablecharacter.h"
#include "dwarf.h"

using namespace std;

Dwarf::Dwarf(): PlayableCharacter{20, 30, 100} {}

string Dwarf::getRace() const {
    return "Dwarf";
}

void Dwarf::addGold(int gold) {
    curGold += 2 * gold;
}

Dwarf::~Dwarf() {}
