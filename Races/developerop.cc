#include "developerop.h"
#include "../Entities/playablecharacter.h"

#include <string>

DeveloperOP::DeveloperOP(): PlayableCharacter{1000000, 1000000, 1000000} {}

std::string DeveloperOP::getRace() const {
    return "OP";
}

DeveloperOP::~DeveloperOP() {}

