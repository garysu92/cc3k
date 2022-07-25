#include "developerup.h"
#include "../Entities/playablecharacter.h"

#include <string>

DeveloperUP::DeveloperUP(): PlayableCharacter{1, 1, 1} {}

std::string DeveloperUP::getRace() const {
    return "UP";
}

DeveloperUP::~DeveloperUP() {}
