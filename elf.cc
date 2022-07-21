#include "elf.h"

using namespace std;

Elf::Elf(): PlayableCharacter{30, 10, 140} {}

string Elf::getRace() const {
    return "Elf";
}

Elf::~Elf() {}
